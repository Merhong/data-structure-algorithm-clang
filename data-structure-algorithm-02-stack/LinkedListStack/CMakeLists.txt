cmake_minimum_required(VERSION 3.27)
project(LinkedListStack C)

set(CMAKE_C_STANDARD 17)

add_executable(LinkedListStack main.c
        LinkedListStack.h
        LinkedListStack.c
)
