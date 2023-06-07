cmake_minimum_required(VERSION 3.25)
project(pure_pursuit_core)

set(CMAKE_CXX_STANDARD 20)

find_package(lart_common REQUIRED)

include_directories(include)

add_library(pure_pursuit_core main.cpp src/PathTracker.cpp include/path_tracker/PathTracker.h)
