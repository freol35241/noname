#include "noname/entity.hpp"

#include "noname/connection.hpp"
#include "noname/function_block.hpp"

namespace NoName {

  void Entity::evaluate() { this->evaluate(0.0); };
  void Entity::evaluate(double time){
      // Execute according to topological sort
  };

  void Entity::add_block(const std::shared_ptr<FunctionBlock> block) {
    this->registry.emplace(std::type_index(typeid(*block.get())), block);
  };
  void Entity::add_entity(const std::shared_ptr<Entity>& entity){
      // Not implemented yet!
  };

}  // namespace NoName