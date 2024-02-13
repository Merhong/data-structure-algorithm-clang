cmake_minimum_required(VERSION 3.27)
project(LinkedQueue C)

set(CMAKE_C_STANDARD 17)

add_executable(LinkedQueue main.c
        LinkedQueue.c)
