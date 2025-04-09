cmake_minimum_required(VERSION 3.14)

project(DesignPatterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(abstract-factory/)
add_subdirectory(builder/)
add_subdirectory(factory-method/)

