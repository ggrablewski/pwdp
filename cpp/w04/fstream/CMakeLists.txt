cmake_minimum_required(VERSION 3.10)
project(ifstream)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ifstream ifstream.cpp)
add_executable(ofstream ofstream.cpp)
