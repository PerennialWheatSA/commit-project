cmake_minimum_required(VERSION 3.0.0)
project(cpplinux VERSION 0.1.0)

set(CMAKE_CXX_FLAGS " -pthread ${CMAKE_CXX_FLAGS}")
add_executable(cpplinux main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
