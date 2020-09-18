project(dynobj_host)

set(SOURCES
    object_host_impl.cpp)

if(WIN32)
    list(APPEND SOURCES
        object_loader_win32.cpp)
else(WIN32)
    list(APPEND SOURCES
        object_loader_linux.cpp)
endif(WIN32)

file(GLOB INTERFACES "${DYNOBJ_INCLUDE_DIR}/dynobj/host/*.h")
file(GLOB HEADERS "*.h")

source_group("Interfaces" FILES ${INTERFACES})
source_group("Header Files" FILES ${HEADERS})

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS} ${INTERFACES})

include(tests/dynobj_host_tests.cmake OPTIONAL)