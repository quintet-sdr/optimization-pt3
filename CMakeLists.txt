cmake_minimum_required(VERSION 3.28)
project(optimization_pt3)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/headers)

add_executable(optimization_pt3
        src/headers/matrix.cpp
        src/headers/matrix.h
        src/headers/methods.h
        src/headers/north-west.cpp
        src/headers/russel.cpp
        src/headers/vogel.cpp
        src/main.cpp)
