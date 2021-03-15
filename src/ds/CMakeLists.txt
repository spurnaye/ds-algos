add_subdirectory(LinkedList)
add_subdirectory(StackWLinkedList)
add_subdirectory(SmartPointer)
add_subdirectory(LockFree)
add_subdirectory(OptimizedString)
set(SOURCE_FILES main.cpp)


set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(llist ${SOURCE_FILES})
add_library(DataStructures SHARED ${SOURCE_FILES} )
target_link_libraries (llist ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS llist RUNTIME DESTINATION bin)
