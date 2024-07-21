cmake_minimum_required(VERSION 3.13)
project(mAlgorithm)
set(CMAKE_CXX_STANDARD 11)

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include
)

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE release CACHE STRING "Build Type" FORCE)
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL release)
    add_definitions(-DRELEASE_)
    message(STATUS "config type: RELEASE")
else()
    add_definitions(-DDEBUG_)
    message(STATUS "config type: DEBUG")
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_library(${PROJECT_NAME} SHARED
    src/sort/sort.cpp
    src/sort/sort_sub.cpp
)
target_link_directories(${PROJECT_NAME}
    PRIVATE include
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/TESTFILE)
add_executable(unitTestRunner src/TESTFILE/runtest.cpp)
target_link_libraries(unitTestRunner ${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)