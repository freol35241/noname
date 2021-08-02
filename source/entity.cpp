#include "noname/entity.hpp"

#include "noname/block.hpp"
#include "noname/connection.hpp"
#include "noname/toposort.hpp"

namespace NoName {

  void Entity::evaluate() { this->evaluate(0.0); };
  void Entity::evaluate(double time) {
    // Treating function blocks as vertices and a subset of the connections as edges to construct an
    // execution graph

    std::vector<std::shared_ptr<Block>> blocks(this->block_registry.size());
    for (auto& [key, block] : this->block_registry) {
      blocks.push_back(block);
    }

    // Create execution graph
    auto adjacency_map = construct_adjacency_map(blocks, this->connections);
    auto vertex_order = topological_sort(blocks, adjacency_map);

    // Execute according to topological sort
    for (auto& idx : vertex_order) {
      // Fetch block according to execution order
      auto block = blocks[idx];

      // Check if we have any in-bound connections to this block, if so, execute these
      if (adjacency_map.count(block) > 0) {
        for (auto& con : adjacency_map[block]) {
          con->execute();
        }
      }

      // Finally, evaluate this block
      block->evaluate(time);
    }
  };

  void Entity::add_block(std::shared_ptr<Block> block) {
    this->block_registry.emplace(std::type_index(typeid(*block.get())), block);
  };

  void Entity::add_connection(std::shared_ptr<Connection> connection) {
    this->connections.emplace_back(connection);
  };

  template <typename T> std::vector<std::shared_ptr<T>> Entity::get_block() {
    auto [first, last] = this->block_registry.equal_range(std::type_index(typeid(T)));

    std::vector<std::shared_ptr<T>> out;
    for (auto it = first; it != last; ++it) {
      out.push_back(std::static_pointer_cast<T>(it->second));
    }
    return out;
  };

  Entity merge_entities(const Entity& first, const Entity& second) {
    Entity merged;

    // First entity
    for (auto& [key, block] : first.block_registry) {
      merged.add_block(block);
    }

    for (auto& con : first.connections) {
      merged.add_connection(con);
    }

    // Second entity
    for (auto& [key, block] : second.block_registry) {
      merged.add_block(block);
    }

    for (auto& con : second.connections) {
      merged.add_connection(con);
    }

    return merged;
  }

}  // namespace NoName