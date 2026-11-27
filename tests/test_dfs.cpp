
#include "terraincraft/algorithms/DFS.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

using namespace terraincraft::graph;
using namespace terraincraft::algorithms;

int main() {

    {
        Graph graph;

        NodeId a = graph.addNode(0, 0);
        NodeId b = graph.addNode(1, 1);
        NodeId c = graph.addNode(2, 2);
        NodeId d = graph.addNode(3, 3);
        NodeId e = graph.addNode(4, 4);

        graph.addUndirectedEdge(a, b, 1);
        graph.addUndirectedEdge(a, c, 1);
        graph.addUndirectedEdge(b, d, 1);
        graph.addUndirectedEdge(b, e, 1);

        vector<NodeId> result = depthFirstSearch(graph, a);

        cout << "\nDFS result size: " << result.size() << endl;
        cout << "DFS traversal: ";

        for (NodeId id : result) {
            cout << id << " ";
        }

        cout << endl;

        assert(result.size() == 5);

        assert(result[0] == a);
        assert(result[1] == c);
        assert(result[2] == b);
        assert(result[3] == e);
        assert(result[4] == d);

        cout << "[PASS] Normal DFS traversal\n";
    }

    {
        Graph graph;

        NodeId a = graph.addNode(0, 0);
        NodeId b = graph.addNode(1, 1);
        NodeId c = graph.addNode(2, 2);

        graph.addUndirectedEdge(a, b, 1);

        vector<NodeId> result = depthFirstSearch(graph, a);

        assert(result.size() == 2);
        assert(result[0] == a);
        assert(result[1] == b);

        cout << "[PASS] Disconnected graph\n";
    }

    {
        Graph graph;

        NodeId a = graph.addNode(0, 0);
        NodeId b = graph.addNode(1, 1);
        NodeId c = graph.addNode(2, 2);

        graph.addUndirectedEdge(a, b, 1);
        graph.addUndirectedEdge(b, c, 1);
        graph.addUndirectedEdge(c, a, 1);

        vector<NodeId> result = depthFirstSearch(graph, a);

        assert(result.size() == 3);

        cout << "[PASS] Cycle handling\n";
    }

    {
        Graph graph;

        NodeId a = graph.addNode(0, 0);

        vector<NodeId> result = depthFirstSearch(graph, a);

        assert(result.size() == 1);
        assert(result[0] == a);

        cout << "[PASS] Single-node graph\n";
    }

    {
        Graph graph;

        graph.addNode(0, 0);

        bool exceptionThrown = false;

        try {
            depthFirstSearch(graph, 10);
        }
        catch (const out_of_range&) {
            exceptionThrown = true;
        }

        assert(exceptionThrown);

        cout << "[PASS] Invalid starting Node ID\n";
    }


    {
        Graph graph;

        bool exceptionThrown = false;

        try {
            depthFirstSearch(graph, 0);
        }
        catch (const out_of_range&) {
            exceptionThrown = true;
        }

        assert(exceptionThrown);

        cout << "[PASS] Empty graph\n";
    }

    cout << "\nAll DFS tests passed!\n";

    return 0;
}
