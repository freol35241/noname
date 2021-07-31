#pragma once

#include <typeindex>
#include <typeinfo>
#include <vector>

#include "boost/graph/adjacency_list.hpp"

namespace NoName {

  // Forward declarations
  struct FunctionBlock;
  struct Connection;

  struct Entity {
    using BlockRegistry = std::multimap<std::type_index, std::shared_ptr<FunctionBlock>>;
    using ConnectionRegistry = std::vector<std::shared_ptr<Connection>>;

    BlockRegistry registry;
    ConnectionRegistry pre_connections;
    ConnectionRegistry post_connections;

    void evaluate();
    void evaluate(double time);

    void add_block(std::shared_ptr<FunctionBlock> block);
    void add_entity(const std::shared_ptr<Entity>& entity);
  };

}  // namespace NoName
