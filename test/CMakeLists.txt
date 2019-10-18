project(avl_tree_unit_test)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(../include)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}
        main.cpp avl_tree_test.cpp)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})