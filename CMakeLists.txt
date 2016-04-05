cmake_minimum_required(VERSION 3.3)
project(List)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DoubleLinkedList.cpp DoubleLinkedList.h MyIterator.cpp MyIterator.h)
add_executable(List ${SOURCE_FILES})