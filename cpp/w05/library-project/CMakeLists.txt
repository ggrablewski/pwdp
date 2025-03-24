cmake_minimum_required(VERSION 3.10)
project(library-project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(library-project main.cpp)
target_link_libraries(library-project PUBLIC lz4)
