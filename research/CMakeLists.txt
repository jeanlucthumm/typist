cmake_minimum_required(VERSION 3.6)
project(typist)

set(CMAKE_CXX_STANDARD 11)

add_executable(sequence sequence_finder.cpp)
add_executable(problem problem_finder.cpp)

