cmake_minimum_required(VERSION 3.27)
project(CircularDoublyLinkedList C)

set(CMAKE_C_STANDARD 17)

add_executable(CircularDoublyLinkedList main.c
        CircularDoublyLinkedList.c
        CircularDoublyLinkedLish.h)
