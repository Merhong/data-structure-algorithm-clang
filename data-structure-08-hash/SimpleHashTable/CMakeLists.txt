cmake_minimum_required(VERSION 3.27)
project(SimpleHashTable C)

set(CMAKE_C_STANDARD 11)

add_executable(SimpleHashTable
        SimpleHashTable.c
        Test_SimpleHashTable.c)
