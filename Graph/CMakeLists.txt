cmake_minimum_required(VERSION 3.15)
project(CLIONPROYECT)

set(CMAKE_CXX_STANDARD 14)


add_executable(CLIONPROYECT main.cpp graph.h UndirectedGraph.h Algorithms/kruskal.h Algorithms/dsarray.h
        Algorithms/bfs.h Algorithms/dfs.h)


