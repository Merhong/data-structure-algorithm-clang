cmake_minimum_required(VERSION 3.27)
project(ExpressionTree C)

set(CMAKE_C_STANDARD 11)

add_executable(ExpressionTree main.c
        ExpressionTree.h
        ExpressionTree.c)
