cmake_minimum_required(VERSION 3.27)
project(DisjointSet C)

set(CMAKE_C_STANDARD 11)

add_executable(DisjointSet main.c
        DisjointSet.h
        DisjointSet.c)
