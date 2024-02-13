cmake_minimum_required(VERSION 3.27)
project(CircularQueue C)

set(CMAKE_C_STANDARD 17)

add_executable(CircularQueue main.c
        CircularQueue.h
        CircularQueue.c)
