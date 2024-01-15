cmake_minimum_required(VERSION 3.27)
project(ArrayStack C)

set(CMAKE_C_STANDARD 17)

add_executable(ArrayStack main.c
        ArrayStack.c)
