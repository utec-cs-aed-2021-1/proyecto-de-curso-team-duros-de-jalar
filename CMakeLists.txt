cmake_minimum_required(VERSION 3.17)
project(proyecto_de_curso_team_duros_de_jalar_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(Graph)
include_directories(Graph/Algorithms)
include_directories(Tester)

add_executable(CLIONPROYECT main.cpp Graph Tester

        )
