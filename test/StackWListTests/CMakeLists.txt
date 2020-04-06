include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES StackWListTests.cpp)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(StackWListTests  ${SOURCE_FILES})

add_test(StackWListTests ${CMAKE_BINARY_DIR}/StackWListTests)

target_link_libraries (StackWListTests LinkedList gtest gtest_main gmock_main )
install(TARGETS StackWListTests  DESTINATION ${STACKWLIST_INSTALL_BIN_DIR})
