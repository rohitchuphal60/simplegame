cmake_minimum_required(VERSION 3.10)
project(TextEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all source files
file(GLOB_RECURSE SOURCES
    main.cpp
   
)


# Create executable
add_executable(TextEditor ${SOURCES})
