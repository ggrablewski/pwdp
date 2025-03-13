cmake_minimum_required(VERSION 3.10)
project(interfaces)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pgm-interfaces pgm.cpp pgm.h main.cpp)


