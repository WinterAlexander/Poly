cmake_minimum_required(VERSION 3.7)
project(Poly)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp polynomial.cpp polynomial.h term.cpp term.h template_util.h)
add_executable(Poly ${SOURCE_FILES})


add_subdirectory(gtest)