cmake_minimum_required(VERSION 3.2)

project(algos)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3 -g")

add_subdirectory(googletest-1.10.x)
enable_testing()
find_package (Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
include_directories(src)
include_directories(test)

add_subdirectory(src)
add_subdirectory(test)
