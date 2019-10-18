project(avl_tree_unit_test)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(../include)

add_executable(${PROJECT_NAME}
        main.cpp main.cpp)

target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})