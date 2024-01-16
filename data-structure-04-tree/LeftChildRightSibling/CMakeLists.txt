cmake_minimum_required(VERSION 3.27)
project(LeftChildRightSibling C)

set(CMAKE_C_STANDARD 11)

add_executable(LeftChildRightSibling main.c
        LCRSTree.h
        LCRSTree.c)
