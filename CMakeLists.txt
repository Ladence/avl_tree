cmake_minimum_required(VERSION 3.14)

option(BUILD_UNIT_TEST "Build the unit tests" ON)

if (BUILD_UNIT_TEST)
    add_subdirectory(test)
endif ()