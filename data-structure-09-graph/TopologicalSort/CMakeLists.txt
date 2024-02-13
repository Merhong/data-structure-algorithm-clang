cmake_minimum_required(VERSION 3.28)
project(TopologicalSort C)

set(CMAKE_C_STANDARD 11)

add_executable(TopologicalSort
        Graph.c
        LinkedList.c
        Test_TopologicalSort.c
        TopologicalSort.c
)
