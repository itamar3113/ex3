# The first line states the minimum CMake version to use with this project
# and is requires by CMake.
cmake_minimum_required(VERSION 2.8.0)
set(CMAKE_CXX_STANDARD 11)

# Set <PROJNAME> to be your project name. We set CXX (C++) here as the target language.
project(Mtmchkin  LANGUAGES CXX)

# If you want to see "under the hood" of CMake, uncomment this:
# set(CMAKE_VERBOSE_MAKEFILE ON)

# Define variables containing compiler flags for gcc
set(MTM_FLAGS_DEBUG "-std=c++11 --pedantic-errors -Wall -Werror")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

# Set the flags for gcc
set(CMAKE_CPP_FLAGS ${MTM_FLAGS_DEBUG})


# Add the names of your source files here
set(CPP_FILES "Player.cpp" "Card.cpp" "Main.cpp" "utilities.cpp")

add_executable(mtmchkin ${CPP_FILES})