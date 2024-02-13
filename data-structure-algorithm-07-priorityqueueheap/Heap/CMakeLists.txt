cmake_minimum_required(VERSION 3.27)
project(Heap C)

set(CMAKE_C_STANDARD 11)

add_executable(Heap
        Heap.c
        Heap.h
        Test_Heap.c)
