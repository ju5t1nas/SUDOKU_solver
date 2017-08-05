cmake_minimum_required(VERSION 3.7)
project(SUDOKU_solver)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp board.cpp board.h GLogLinkedList.cpp GLogLinkedList.h)
add_executable(SUDOKU_solver ${SOURCE_FILES})