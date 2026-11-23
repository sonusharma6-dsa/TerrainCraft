#pragma once

#include <cstddef>
using namespace std;

namespace terraincraft::graph {
using NodeId = size_t;
struct Node{
    NodeId id;
    double longitude;   // started with most basic structure that we will have a node with its longitude and latitude and id
    double latitude;
};
}
