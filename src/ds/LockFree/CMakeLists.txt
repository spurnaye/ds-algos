file(GLOB BINARY_SEARCH_SOURCE_FILES SPSCIntQueue.cpp)
set(LOCKFREE_SOURCE_FILES SPSCIntQueue.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_library(SPSCIntQueue SHARED ${LOCKFREE_SOURCE_FILES})
target_link_libraries(SPSCIntQueue ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS SPSCIntQueue RUNTIME DESTINATION bin)


add_executable(lockFreeDS main.cpp)
target_link_libraries(lockFreeDS SPSCIntQueue)

add_executable(lfqHeadOnly NodeBasedQueueHeadOnly.cpp)