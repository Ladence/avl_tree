cmake_minimum_required(VERSION 3.14)

project(avl_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp avl_tree.hpp)