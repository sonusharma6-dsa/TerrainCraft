#include"Node.hpp"
#include"Edge.hpp"
#include<vector>

using namespace std;
class Graph{
private:
    vector<Node> nodes;
    vector<vector<Edge>> adjacency;

    NodeId addNode(double longitude,double latitude);

    NodeId addDirectedEdge(NodeId  from , NodeId  to , double weight);

    NodeId addUndirectedEdge(NodeId from , NodeId to, double weight);

    const Node& getNode(NodeId id)const;

    const vector<Edge>& getNeighbours(NodeId id)const;

    NodeId nodeCount() const;


};
