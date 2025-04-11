cmake_minimum_required(VERSION 3.10)
project(sfml)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics)

add_executable(sfml sfml.cpp)
target_link_libraries(sfml PRIVATE SFML::Graphics)

get_target_property(_aliased SFML::Graphics IMPORTED_TARGET)
#if(_aliased)
  message(STATUS "The name SFML::Graphics is an ALIAS for ${_aliased}.")
#endif()
