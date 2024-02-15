cmake_minimum_required(VERSION 3.28)
project(NQueens C)

set(CMAKE_C_STANDARD 11)

add_executable(NQueens
        NQueens.c
        Test_NQueens.c)
