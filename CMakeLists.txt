cmake_minimum_required(VERSION 3.16)

project(dynobj VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Doxygen REQUIRED)

doxygen_add_docs(doxygen
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

add_subdirectory(private)