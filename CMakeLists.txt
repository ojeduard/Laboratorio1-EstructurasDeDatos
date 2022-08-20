cmake_minimum_required(VERSION 3.21)
project(palabras)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(palabras
        main.cpp
        palabras.cpp
        palabras.h)
