file(GLOB BINARY_SEARCH_SOURCE_FILES SPSCSpinLockQueue.cpp)
set(LOCKFREE_SOURCE_FILES SPSCSpinLockQueue.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_library(SPSCIntQueue SHARED ${LOCKFREE_SOURCE_FILES})
target_link_libraries(SPSCIntQueue ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS SPSCIntQueue RUNTIME DESTINATION bin)


add_executable(lockFreeDS main.cpp)
add_executable(lockFreeSPSCStack SPSCLockFreeStack.cpp)

target_link_libraries(lockFreeDS SPSCIntQueue)

add_executable(lfqHeadOnly NodeBasedQueueHeadOnly.cpp)

add_executable(SPSCLockFreeQueue SPSCLockFreeQueue.cpp)