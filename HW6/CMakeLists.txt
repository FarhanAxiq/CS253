cmake_minimum_required(VERSION 3.14)
project(hw6)
 
# Are we in the wrong directory?
if(CMAKE_SOURCE_DIR MATCHES "[Hh][Ww]([0-9])$")
   if(PROJECT_NAME MATCHES "[^${CMAKE_MATCH_1}]$")
      message(FATAL_ERROR "Building ${PROJECT_NAME} in ${CMAKE_SOURCE_DIR}")
   endif()
endif()
 
# Using -Wall is required:
add_compile_options(-Wall)
 
# These compile flags are highly recommended, but not required:

# Optional super-strict mode:
add_compile_options(-fmessage-length=80 -fno-diagnostics-show-option
    -fstack-protector-all -g -O3 -std=c++17 -Wall)
 
# add_compile_options must be BEFORE add_executable.
 
# Create the executable from the source file main.cc:
add_library(${PROJECT_NAME} Rule.cc Rule.h Board.cc Board.h)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME})
 
# Create a tar file every time:
add_custom_target(${PROJECT_NAME}.tar ALL COMMAND
    tar -cf ${PROJECT_NAME}.tar Rule.cc Rule.h Board.cc Board.h libhw6.a CMakeLists.txt)