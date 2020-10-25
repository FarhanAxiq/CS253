cmake_minimum_required(VERSION 3.14)
project(hw4)

# Are we in the wrong directory?
if(CMAKE_SOURCE_DIR MATCHES "[Hh][Ww]([0-9])$")
   if(PROJECT_NAME MATCHES "[^${CMAKE_MATCH_1}]$")
      message(FATAL_ERROR "Building ${PROJECT_NAME} in ${CMAKE_SOURCE_DIR}")
   endif()
endif()

# Using -Wall is required:
add_compile_options(-Wall)

# add_compile_options must be BEFORE add_executable.

# Create the executable from the source file main.cc:
add_executable(${PROJECT_NAME} GameOfLife.h GameOfLife.cc)

# Create a tar file every time:
add_custom_target(${PROJECT_NAME}.tar ALL COMMAND
    tar -cf ${PROJECT_NAME}.tar GameOfLife.cc GameOfLife.h CMakeLists.txt)