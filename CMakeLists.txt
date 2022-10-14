cmake_minimum_required(VERSION 3.12)
project(skallaquad)

set(TARGET_GROUP production CACHE STRING "Group to build")


###############################################################
# Create shared library
###############################################################
add_library(${PROJECT_NAME} SHARED
    src/skallaquad.c
)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        m
)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)


###############################################################
# Create Test Runner
###############################################################
if(TARGET_GROUP STREQUAL test)
    include(CTest)

    add_subdirectory(external)
    add_subdirectory(tests)
else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()

