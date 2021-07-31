#include "noname/entity.hpp"

#include "noname/block.hpp"
#include "noname/connection.hpp"

namespace NoName {

  void Entity::evaluate() { this->evaluate(0.0); };
  void Entity::evaluate(double time){
      // Execute according to topological sort
  };

  void Entity::add_block(const std::shared_ptr<Block> block) {
    this->registry.emplace(std::type_index(typeid(*block.get())), block);
    };
  void Entity::add_entity(const std::shared_ptr<Entity>& entity){
      // Not implemented yet!
  };

  template <typename T> std::vector<std::shared_ptr<T>> Entity::get_block() {
    auto [first, last] = this->registry.equal_range(std::type_index(typeid(T)));

    std::vector<std::shared_ptr<T>> out;
    for (auto it = first; it != last; ++it) {
      out.push_back(std::static_pointer_cast<T>(it->second));
    }
    return out;
  };

}  // namespace NoName