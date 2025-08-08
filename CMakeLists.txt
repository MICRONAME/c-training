cmake_minimum_required(VERSION 3.29)
project(c-training)

add_subdirectory(C-problems)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")