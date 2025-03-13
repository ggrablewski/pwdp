cmake_minimum_required (VERSION 3.10)
project(fmtlib-demo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fmtlib-demo main.cpp)
target_link_libraries(fmtlib-demo PUBLIC fmt)

