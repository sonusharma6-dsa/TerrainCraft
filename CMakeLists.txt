
cmake_minimum_required(VERSION 3.20)

project(TerrainCraft
    VERSION 0.1.0
    DESCRIPTION "C++ Geospatial Routing Engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Graph library
add_library(terraincraft_graph
    src/graph/Graph.cpp
)

target_include_directories(terraincraft_graph
    PUBLIC include
)

# Algorithms library
add_library(terraincraft_algorithms
    src/algorithms/BFS.cpp
)

target_include_directories(terraincraft_algorithms
    PUBLIC include
)

target_link_libraries(terraincraft_algorithms
    PUBLIC terraincraft_graph
)


add_executable(terraincraft
    src/main.cpp
)

target_link_libraries(terraincraft
    PRIVATE terraincraft_algorithms
)

# Testing
enable_testing()

add_executable(test_graph
    tests/test_graph.cpp
)

target_link_libraries(test_graph
    PRIVATE terraincraft_graph
)

add_test(
    NAME graph_tests
    COMMAND test_graph
)

add_executable(test_bfs tests/test_bfs.cpp)

target_link_libraries(test_bfs PRIVATE terraincraft_algorithms)

add_test(NAME bfs_tests COMMAND test_bfs)