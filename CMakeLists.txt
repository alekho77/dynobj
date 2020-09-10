cmake_minimum_required(VERSION 3.16)

project(dynobj)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(DYNOBJ_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(
    ${DYNOBJ_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/private)

enable_testing()

add_subdirectory(private)