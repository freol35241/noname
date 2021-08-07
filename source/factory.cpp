#include "noname/factory.hpp"

#include <exception>

namespace NoName {
  void BlockFactory::register_builder(std::string key, BlockBuilder builder) {
    this->registry.emplace(key, builder);
  };

  std::shared_ptr<Block> BlockFactory::build(std::string key, const nlohmann::json& j) {
    if (this->registry.count(key) == 0) {
      throw std::runtime_error("No such Block has been registered with the BlockFactory!");
    }
    return this->registry[key](j);
  };

  BlockFactory& get_block_factory() {
    static BlockFactory factory;
    return factory;
  }
}  // namespace NoName