cmake_minimum_required(VERSION 3.28)
project(Huffman C)

set(CMAKE_C_STANDARD 11)

add_executable(Huffman
        PriorityQueue.c
        Huffman.c
        Test_Huffman.c
        Huffman.h)
