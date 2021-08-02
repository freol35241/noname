#pragma once

#include <map>
#include <memory>
#include <typeindex>
#include <typeinfo>
#include <vector>

namespace NoName {

  // Forward declarations
  struct Block;
  struct Connection;

  struct Entity {
    using BlockRegistry = std::multimap<std::type_index, std::shared_ptr<Block>>;

    BlockRegistry block_registry;
    std::vector<std::shared_ptr<Connection>> connections;

    void evaluate();
    void evaluate(double time);

    void add_block(std::shared_ptr<Block> block);
    void add_connection(std::shared_ptr<Connection> connection);

    template <typename T> std::vector<std::shared_ptr<T>> get_block();
  };

  // TODO(freol35241): Should preferably accept any number of inout Entity arguments
  Entity merge_entities(const Entity& first, const Entity& second);

}  // namespace NoName
