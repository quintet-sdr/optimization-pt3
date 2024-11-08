cmake_minimum_required(VERSION 3.28)
project(optimization_pt3)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE src/main.cpp)
set(HEADER src/headers/methods.hpp src/headers/matrix.hpp)

include_directories(src)
add_library(matrix src/headers/matrix.cpp
        src/headers/north_west.cpp)
add_library(vogel src/headers/vogel.cpp)

add_executable(optimization_pt3 src/main.cpp)
target_link_libraries(optimization_pt3 matrix)
target_link_libraries(optimization_pt3 vogel)
