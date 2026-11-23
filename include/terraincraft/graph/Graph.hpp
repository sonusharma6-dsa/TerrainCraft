#pragma once

#include "Node.hpp"
#include "Edge.hpp"

#include <cstddef>
#include <vector>

using namespace std;
namespace terraincraft::graph {

class Graph {

private:
    vector<Node> nodes;
    vector<vector<Edge>> adjacency;

public:
    NodeId addNode(double longitude, double latitude);

    void addDirectedEdge(NodeId from, NodeId to, double weight); //note that we can write  size_int as int also

    void addUndirectedEdge(NodeId from, NodeId to, double weight);

    const Node& getNode(NodeId id) const;

    const vector<Edge>& getNeighbors(NodeId id) const;

    size_t nodeCount() const;

};
}