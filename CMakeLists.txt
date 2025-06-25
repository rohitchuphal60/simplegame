cmake_minimum_required(VERSION 3.10)
project(TextEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all source files
file(GLOB_RECURSE SOURCES
    main.cpp
    core/*.cpp
    ui/*.cpp
    modes/*.cpp
    command/*.cpp
    syntax/*.cpp
    plugin/*.cpp
    util/*.cpp
)

# Include directories
include_directories(
    core
    ui
    modes
    command
    syntax
    plugin
    util
)

# Create executable
add_executable(TextEditor ${SOURCES})
