#include <queue>
#include <vector>
#include <stdexcept>
#include"terraincraft/algorithms/BFS.hpp"



using namespace std;
using terraincraft::graph::NodeId;
namespace terraincraft::algorithms{

    
vector<terraincraft::graph::NodeId> breadthFirstSearch(const terraincraft::graph::Graph& graph,
        terraincraft::graph::NodeId start ){

if (start >= graph.nodeCount()) {
    throw out_of_range("Invalid starting Node ID");
}
vector<bool> visited(graph.nodeCount(), false);
queue<NodeId> pending;
vector<NodeId> order;


visited[start] = true;
pending.push(start);

while (!pending.empty()) {

    NodeId current = pending.front();
    pending.pop();
    order.push_back(current);

    for (const auto& edge : graph.getNeighbors(current)) {

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

