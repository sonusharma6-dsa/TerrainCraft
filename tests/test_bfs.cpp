#include <cassert>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "terraincraft/algorithms/BFS.hpp"
#include "terraincraft/graph/Graph.hpp"

using namespace std;
using namespace terraincraft::graph;
using namespace terraincraft::algorithms;

int main() {

    
    {
        Graph graph;

        NodeId delhi  = graph.addNode(77.2090, 28.6139);
        NodeId jaipur = graph.addNode(75.7873, 26.9124);
        NodeId agra   = graph.addNode(78.0081, 27.1767);
        NodeId mumbai = graph.addNode(72.8777, 19.0760);

        graph.addDirectedEdge(delhi, jaipur, 280.0);
        graph.addDirectedEdge(delhi, mumbai, 1400.0);
        graph.addDirectedEdge(jaipur, agra, 240.0);
        graph.addDirectedEdge(mumbai, agra, 1200.0);

        vector<NodeId> expected = {
            delhi, jaipur, mumbai, agra
        };

        assert(breadthFirstSearch(graph, delhi) == expected);

        cout << "[PASS] Normal BFS traversal\n";
    }


    {
        Graph graph;

        NodeId a = graph.addNode(77.0, 28.0);
        NodeId b = graph.addNode(75.0, 26.0);
        NodeId c = graph.addNode(72.0, 19.0);
        NodeId d = graph.addNode(73.0, 18.0);

        graph.addDirectedEdge(a, b, 100.0);
        graph.addDirectedEdge(c, d, 150.0);

        vector<NodeId> expected = {a, b};

        assert(breadthFirstSearch(graph, a) == expected);

        cout << "[PASS] Disconnected graph\n";
    }


    {
        Graph graph;

        NodeId a = graph.addNode(77.0, 28.0);
        NodeId b = graph.addNode(75.0, 26.0);
        NodeId c = graph.addNode(72.0, 19.0);
        NodeId d = graph.addNode(73.0, 18.0);

        graph.addDirectedEdge(a, b, 100.0);
        graph.addDirectedEdge(a, c, 200.0);
        graph.addDirectedEdge(b, d, 150.0);
        graph.addDirectedEdge(c, d, 250.0);
        graph.addDirectedEdge(d, a, 300.0);

        vector<NodeId> expected = {a, b, c, d};
        assert(breadthFirstSearch(graph, a) == expected);

        cout << "[PASS] Cycle and duplicate visits\n";
    }

    {
        Graph graph;
        NodeId onlyNode = graph.addNode(77.2090, 28.6139);
        vector<NodeId> expected = {onlyNode};

        assert(breadthFirstSearch(graph, onlyNode) == expected);

        cout << "[PASS] Single-node graph\n";
    }

    
    {
        Graph graph;

        graph.addNode(77.2090, 28.6139);

        bool exceptionCaught = false;

        try {
            breadthFirstSearch(graph, 99);
        }
        catch (const out_of_range&) {
            exceptionCaught = true;
        }

        assert(exceptionCaught);

        cout << "[PASS] Invalid starting NodeId\n";
    }

  
    {
        Graph graph;

        bool exceptionCaught = false;

        try {
            breadthFirstSearch(graph, 0);
        }
        catch (const out_of_range&) {
            exceptionCaught = true;
        }

        assert(exceptionCaught);

        cout << "[PASS] Empty graph\n";
    }

    cout << "\nAll BFS tests passed!\n";

    return 0;
}
