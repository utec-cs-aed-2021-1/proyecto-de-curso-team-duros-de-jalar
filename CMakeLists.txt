cmake_minimum_required(VERSION 3.15.3)
project(CLIONPROYECT)

set(CMAKE_CXX_STANDARD 14)

include_directories(Graph)
include_directories(Graph/Algorithms)
include_directories(Tester)

add_executable(CLIONPROYECT main.cpp Graph Tester)

