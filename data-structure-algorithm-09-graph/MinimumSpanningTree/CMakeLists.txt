cmake_minimum_required(VERSION 3.28)
project(MinimumSpanningTree C)

set(CMAKE_C_STANDARD 11)

add_executable(MinimumSpanningTree
        Test_MST.c
        MST.c
        DisjointSet.c
        Graph.c
        PriorityQueue.c
        MST.h)
