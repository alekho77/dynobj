find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

if(WIN32)
    set(GTEST_ROOT "${CMAKE_PREFIX_PATH}/GTest" CACHE PATH "Path to googletest")
endif(WIN32)

find_package(GTest REQUIRED)

__gtest_find_library(GMOCK_LIBRARY            gmock)
__gtest_find_library(GMOCK_LIBRARY_DEBUG      gmockd)
__gtest_find_library(GMOCK_MAIN_LIBRARY       gmock_main)
__gtest_find_library(GMOCK_MAIN_LIBRARY_DEBUG gmock_maind)
__gtest_append_debugs(GTEST_LIBRARIES      GMOCK_LIBRARY)
__gtest_append_debugs(GTEST_MAIN_LIBRARIES GMOCK_MAIN_LIBRARY)

include_directories(${GTEST_INCLUDE_DIRS})

set(DYNOBJ_TEST_LIBRARIES 
    ${GTEST_MAIN_LIBRARIES}
    ${GTEST_LIBRARIES})

if(UNIX)
    list(APPEND DYNOBJ_TEST_LIBRARIES pthread)
endif(UNIX)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(modules)