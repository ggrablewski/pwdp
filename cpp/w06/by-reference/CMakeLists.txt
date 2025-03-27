cmake_minimum_required(VERSION 3.10)
project(by-reference)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(by-reference main.cpp)
add_executable(fun-ref-simple fun-ref-simple.cpp)
add_executable(fun-ref-overloading fun-ref-overloading.cpp)



