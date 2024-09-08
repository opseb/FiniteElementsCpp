# CMake version required
cmake_minimum_required(VERSION 3.8)

# Set the project name
project(FinteElementsCpp)

# Set C++ standard (optional)
set(CMAKE_C14_STANDARD 11)

aux_source_directory(src DIR_SRCS)

add_executable(FEMCpp ${DIR_SRCS})