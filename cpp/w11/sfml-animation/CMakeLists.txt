cmake_minimum_required(VERSION 3.10)
project(sfml-animation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics)

add_executable(sfml animation.cpp)
target_link_libraries(sfml PRIVATE SFML::Graphics)

