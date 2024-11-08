cmake_minimum_required(VERSION 3.10)

project(cmake_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(abstract-factory.out main.cpp)
