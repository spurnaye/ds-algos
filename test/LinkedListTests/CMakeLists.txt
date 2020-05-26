include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES LinkedListTest.cpp)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(LinkedListTests ${SOURCE_FILES})

add_test(LinkedListTests ${CMAKE_BINARY_DIR}/LinkedListTests)

target_link_libraries (LinkedListTests DataStructures gtest gtest_main gmock_main )
install(TARGETS LinkedListTests DESTINATION ${LINKEDLIST_INSTALL_BIN_DIR})
