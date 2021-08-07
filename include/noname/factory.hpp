#pragma once

#include <functional>
#include <memory>
#include <string>

#include "nlohmann/json.hpp"
#include "noname/block.hpp"

namespace NoName {
  using BlockBuilder = std::function<std::shared_ptr<Block>(const nlohmann::json& j)>;

  class BlockFactory {
  private:
    std::map<std::string, BlockBuilder> registry;

  public:
    void register_builder(std::string key, BlockBuilder builder);
    std::shared_ptr<Block> build(std::string key, const nlohmann::json& j);
  };

  BlockFactory& get_block_factory();

#define REGISTER_BLOCK(type)

}  // namespace NoName