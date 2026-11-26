#pragma once

#include <vector>
#include <queue>
#include "terraincraft/graph/Graph.hpp"
using namespace std;
namespace terraincraft::algorithms {
    vector<terraincraft::graph::NodeId> breadthFirstSearch(
        const terraincraft::graph::Graph& graph,
        terraincraft::graph::NodeId start );

} 
