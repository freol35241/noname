#pragma once

#include <memory>
#include <typeindex>
#include <typeinfo>
#include <vector>

#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/graph_traits.hpp"

namespace NoName {

  // Forward declarations
  struct Block;
  struct Connection;

  struct Entity {
    using BlockRegistry = std::multimap<std::type_index, std::shared_ptr<Block>>;
    using ConnectionRegistry = std::vector<std::shared_ptr<Connection>>;

    typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS> Graph;
    Graph graph;

    BlockRegistry registry;
    ConnectionRegistry pre_connections;
    ConnectionRegistry post_connections;

    void evaluate();
    void evaluate(double time);

    void add_block(std::shared_ptr<Block> block);
    void add_entity(const std::shared_ptr<Entity>& entity);

    template <typename T> std::vector<std::shared_ptr<T>> get_block();
  };

}  // namespace NoName
