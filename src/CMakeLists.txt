cmake_minimum_required(VERSION 3.7)
project(Poly_src)

set(CMAKE_CXX_STANDARD 17)


file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp ${PROJECT_SOURCE_DIR}/*.h)
add_executable(Poly ${SOURCE_FILES})

