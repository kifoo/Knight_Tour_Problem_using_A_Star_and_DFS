cmake_minimum_required(VERSION 3.22)
project(Miktoprojekt4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Miktoprojekt4 main.cpp sources/DFS.cpp headers/DFS.h sources/A_Star.cpp headers/A_Star.h sources/Board.cpp headers/Board.h sources/Graph.cpp headers/Graph.h)
