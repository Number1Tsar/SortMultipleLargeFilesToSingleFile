cmake_minimum_required(VERSION 3.14)
project(SortLargeFiles)

set(CMAKE_CXX_STANDARD 14)

add_executable(SortLargeFiles main.cpp FileHandler.cpp FileMerger.cpp)