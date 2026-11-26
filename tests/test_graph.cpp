#include <limits>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include "terraincraft/graph/Graph.hpp"

using namespace std;

using namespace terraincraft::graph;

int main() {

    Graph graph;

    NodeId delhi = graph.addNode(77.2090, 28.6139);
    NodeId jaipur = graph.addNode(75.7873, 26.9124);

    assert(delhi == 0);
    assert(jaipur == 1);
    assert(graph.nodeCount() == 2);

    
    assert(graph.getNode(delhi).longitude == 77.2090);
    assert(graph.getNode(delhi).latitude == 28.6139);


    graph.addDirectedEdge(delhi, jaipur, 280.0);

    assert(graph.getNeighbors(delhi).size() == 1);
    assert(graph.getNeighbors(jaipur).empty());
    assert(graph.getNeighbors(delhi)[0].weight == 280.0);


    bool invalidNodeCaught = false;

    try {
        graph.addDirectedEdge(delhi, 99, 100.0);
    }
    catch (const std::out_of_range&) {
        invalidNodeCaught = true;
    }

    assert(invalidNodeCaught);


    bool invalidWeightCaught = false;

    try {
        graph.addDirectedEdge(delhi, jaipur, -50.0);
    }
    catch (const std::invalid_argument&) {
        invalidWeightCaught = true;
    }

    assert(invalidWeightCaught);



Graph roadGraph;

NodeId cityA = roadGraph.addNode(77.0, 28.0);
NodeId cityB = roadGraph.addNode(75.0, 26.0);

roadGraph.addUndirectedEdge(cityA, cityB, 280.0);

assert(roadGraph.getNeighbors(cityA).size() == 1);
assert(roadGraph.getNeighbors(cityB).size() == 1);

assert(roadGraph.getNeighbors(cityA)[0].weight == 280.0);
assert(roadGraph.getNeighbors(cityB)[0].weight == 280.0);



bool invalidGetNodeCaught = false;

try {
    graph.getNode(99);
}
catch (const std::out_of_range&) {
    invalidGetNodeCaught = true;
}

assert(invalidGetNodeCaught);




bool invalidNeighborsCaught = false;

try {
    graph.getNeighbors(99);
}
catch (const std::out_of_range&) {
    invalidNeighborsCaught = true;
}

assert(invalidNeighborsCaught);



bool infinityCaught = false;

try {
    double weight = std::numeric_limits<double>::infinity();

    graph.addDirectedEdge(delhi, jaipur, weight);
}
catch (const std::invalid_argument&) {
    infinityCaught = true;
}

assert(infinityCaught);



bool nanCaught = false;

try {
    double weight = std::numeric_limits<double>::quiet_NaN();

    graph.addDirectedEdge(delhi, jaipur, weight);
}
catch (const std::invalid_argument&) {
    nanCaught = true;
}

assert(nanCaught);

    cout << "All Graph tests passed!\n";

    return 0;
}
