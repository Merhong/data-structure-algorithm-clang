cmake_minimum_required(VERSION 3.28)
project(Dijkstra C)

set(CMAKE_C_STANDARD 11)

add_executable(Dijkstra
        Graph.c
        PriorityQueue.c
        ShortestPath.c
        Test_ShortestPath.c)
