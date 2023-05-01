#---------------------------------------------------------------------------------------------------
# Voronoi diagram project

cmake_minimum_required(VERSION 3.0)
project(vororamer)

#---------------------------------------------------------------------------------------------------
# Set the C++ standard to C++17

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#---------------------------------------------------------------------------------------------------
# Set warning flags

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

#---------------------------------------------------------------------------------------------------
# Source files

set(SOURCES
    src/main.cpp
    src/Vororamer.cpp
)

#---------------------------------------------------------------------------------------------------
# Add the executable

add_executable(vororamer ${SOURCES})
