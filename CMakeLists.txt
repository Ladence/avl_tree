add_subdirectory(src)

option(BUILD_UNIT_TEST "Build the unit tests" OFF)

if (BUILD_UNIT_TEST)
    add_subdirectory(test)
endif ()