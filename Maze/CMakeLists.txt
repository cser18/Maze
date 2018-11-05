cmake_minimum_required(VERSION 3.10)
project(Maze)

set(CMAKE_CXX_STANDARD 11)

add_executable(Maze main.cpp MazeData.cpp MazeData.h RandomQueue.cpp RandomQueue.h Position.h)