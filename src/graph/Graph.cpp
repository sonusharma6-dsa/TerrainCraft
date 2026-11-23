#include "terraincraft/graph/Graph.hpp"
#include <cmath> // this provides isfinite()
#include <stdexcept>//// this provides out_of_range  , invalid_argument


using namespace std;
namespace terraincraft::graph {


NodeId Graph::addNode(double longitude, double latitude) {

    NodeId id = nodes.size();
    nodes.push_back({id, longitude, latitude});
    adjacency.emplace_back();

    return id;
}

void Graph::addDirectedEdge(NodeId from, NodeId to, double weight) {

    if (from >= nodes.size() || to >= nodes.size()) {
        throw out_of_range("Invalid Node ID");
    }
    if (!isfinite(weight) || weight < 0.0) {
        throw invalid_argument("Invalid edge weight");
    }

    adjacency[from].push_back({to, weight});
}

const vector<Edge>& Graph::getNeighbors(NodeId from) const {
    if (from >= nodes.size()) {
        throw out_of_range("Invalid Node ID");
    }
    return adjacency[from];
}

void Graph::addUndirectedEdge(NodeId from, NodeId to, double weight){

    if (from >= nodes.size() || to >= nodes.size()) {
        throw out_of_range("Invalid Node ID");
    }
    if (!isfinite(weight) || weight < 0.0) {
        throw invalid_argument("Invalid edge weight");
    }

    adjacency[from].push_back({to, weight});
    adjacency[to].push_back({from, weight});

}

const Node& Graph::getNode(NodeId id) const{
    if(id >= nodes.size()){
        throw out_of_range("Invalid ID");
    }
    return nodes[id];
}

 size_t Graph::nodeCount() const{
    return nodes.size() ;
}
} //end
