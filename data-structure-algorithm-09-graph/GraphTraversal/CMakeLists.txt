cmake_minimum_required(VERSION 3.28)
project(GraphTraversal C)

set(CMAKE_C_STANDARD 11)

add_executable(GraphTraversal
        Test_GraphTraversal.c
        GraphTraversal.c
        Graph.c
        LinkedQueue.c)
