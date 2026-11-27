
#include "terraincraft/algorithms/DFS.hpp"

#include <stack>
#include <stdexcept>

using namespace std;
namespace terraincraft::algorithms {

vector<terraincraft::graph::NodeId> depthFirstSearch(
    const terraincraft::graph::Graph& graph,
    terraincraft::graph::NodeId start
) {
    using terraincraft::graph::NodeId;

    if (start >= graph.nodeCount()) {
        throw out_of_range("Please enter valid ID");
    }

    stack<NodeId> pending;
    vector<bool> visited(graph.nodeCount(), false);
    vector<NodeId> order;

    
    visited[start] = true;
    pending.push(start);

    while (!pending.empty()) {

        NodeId current = pending.top();
        pending.pop();
        order.push_back(current);

        const auto& neighbours = graph.getNeighbors(current);

        for (const auto& edge : neighbours) {

            NodeId next = edge.to;
            if (!visited[next]) {
                visited[next] = true;
                pending.push(next);
            }
        }
    }

    return order;
}

}
