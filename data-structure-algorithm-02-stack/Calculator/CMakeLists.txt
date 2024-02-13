cmake_minimum_required(VERSION 3.27)
project(Calculator C)

set(CMAKE_C_STANDARD 17)

add_executable(Calculator main.c
        Calculator.h
        Calculator.c
        LinkedListStack.h
        LinkedListStack.c
)
