#pragma once

#include <map>
#include <memory>
#include <vector>

#include "noname/block.hpp"
#include "noname/connection.hpp"

namespace NoName {

  using Vertex = std::shared_ptr<Block>;
  using Edge = std::shared_ptr<Connection>;

  using AdjacencyMap = std::map<Vertex, std::vector<Edge>>;

  inline AdjacencyMap construct_adjacency_map(const std::vector<Vertex>& vertices,
                                              const std::vector<Edge>& edges) {
    return AdjacencyMap();
  }

  inline std::vector<size_t> topological_sort(const std::vector<Vertex>& vertices,
                                              const AdjacencyMap& adjacency_map) {
    return std::vector<size_t>();
  }
}  // namespace NoName
