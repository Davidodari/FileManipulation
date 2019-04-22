cmake_minimum_required(VERSION 3.13)
project(FileAssignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(FileAssignment src/main.cpp src/FileHandler.cpp include/FileAssignment/FileHandler.h)