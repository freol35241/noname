#pragma once

#include <memory>
#include <optional>

#include "noname/block.hpp"

namespace NoName {

  struct Connection {
    enum ConnectionType { INJECTOR, EJECTOR, DAISY_CHAIN, EDGE };
    ConnectionType type;
    std::optional<std::shared_ptr<Block>> source = std::nullopt;
    std::optional<std::shared_ptr<Block>> target = std::nullopt;

    virtual void execute() = 0;
  };

}  // namespace NoName
