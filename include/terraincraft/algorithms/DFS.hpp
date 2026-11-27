#pragma once

#include"terraincraft/graph/Graph.hpp"
#include<vector>

using namespace std;
namespace terraincraft::algorithms{

    vector< terraincraft::graph::NodeId> depthFirstSearch(
        const terraincraft::graph::Graph& graph,
        terraincraft::graph::NodeId start 
    );

}