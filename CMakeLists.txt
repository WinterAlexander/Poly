cmake_minimum_required(VERSION 3.7)
project(Poly)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp polynomial.cpp polynomial.h)
add_executable(Poly ${SOURCE_FILES})