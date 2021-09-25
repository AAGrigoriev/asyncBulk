cmake_minimum_required(VERSION 3.18)

project(bulk_async)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bulk_exe src/main.cpp)

include_directories("inc/")
