set(TESTS_SOURCES
    tests/object_host_test.cpp)

set(TEST_LIBRARIES
    ${PROJECT_NAME}
    ${DYNOBJ_TEST_LIBRARIES})

add_executable(${PROJECT_NAME}_test ${TESTS_SOURCES})
target_link_libraries(${PROJECT_NAME}_test ${TEST_LIBRARIES})

add_test(${PROJECT_NAME}_tests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}_test)