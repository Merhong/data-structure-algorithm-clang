cmake_minimum_required(VERSION 3.28)
project(MazeSolver C)

set(CMAKE_C_STANDARD 11)

add_executable(MazeSolver
        MazeSolver.h
        MazeSolver.c
        Test_MazeSolver.c)
