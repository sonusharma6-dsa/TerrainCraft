#include <iostream>
#include "terraincraft/graph/Graph.hpp"
#include<stdexcept>
namespace tc = terraincraft::graph;
using namespace std;
int main() {

    tc::Graph network;

    tc::NodeId delhi = network.addNode(77.2090, 28.6139);
    tc::NodeId jaipur = network.addNode(75.7873, 26.9124);
    tc::NodeId mumbai= network.addNode(72.8777, 19.0760);

    cout << "Delhi Node ID: " << delhi << '\n';
    cout << "Jaipur Node ID: " << jaipur << '\n';
    cout << "Mumbai Node ID: " << mumbai << '\n';

    network.addDirectedEdge(delhi , mumbai,678.5);
    network.addUndirectedEdge(jaipur , mumbai,238);

    const auto& neighbors = network.getNeighbors(mumbai);

    for (const auto& edge : neighbors) {

    cout << "Destination: " << edge.to << '\n';
    cout << "Distance : " << edge.weight<< '\n';
  }
const auto& mumbaiNeighbors = network.getNeighbors(mumbai);

cout << "Mumbai outgoing edges: "<< mumbaiNeighbors.size() << '\n';

const auto& city = network.getNode(mumbai);


cout << "\nRetrieved Node:\n";
cout << "ID: " << city.id << '\n';
cout << "Longitude: " << city.longitude << '\n';
cout << "Latitude: " << city.latitude << '\n';

auto TotalNodes = network.nodeCount();
cout<<"Total Nodes :"<<TotalNodes<<endl;

try{
    network.addDirectedEdge(delhi, 99, 100.0);
}
catch(const out_of_range& error){
    cout << "Caught error: " << error.what() << '\n';
}

try {
    network.addDirectedEdge(delhi, jaipur, -50.0);
}
catch (const std::invalid_argument& error) {
    cout << "Caught error: " << error.what() << '\n';
}
cout << "Delhi edges: "
     << network.getNeighbors(delhi).size() << '\n';

cout << "Jaipur edges: "
     << network.getNeighbors(jaipur).size() << '\n';

cout << "Mumbai edges: "<< network.getNeighbors(mumbai).size() << '\n';

    return 0;
}
