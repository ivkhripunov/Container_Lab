cmake_minimum_required(VERSION 3.22)
project(container_lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(container_lab subforward_list.h subvector.h "#7.cpp")
