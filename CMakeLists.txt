project(compile_time)
cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
enable_testing()

include_directories(include)
add_subdirectory(test)