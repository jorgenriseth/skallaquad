cmake_minimum_required(VERSION 3.12)

project(skallaquad)

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
# Create executable binary to verify
###############################################################

add_executable(${PROJECT_NAME}_TEST src/run_integration.c)
target_link_libraries(${PROJECT_NAME}_TEST
    PRIVATE
        m
        ${PROJECT_NAME}
)
