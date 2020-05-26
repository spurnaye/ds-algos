include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES SmartPointerTest.cpp)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(SmartPointerTests ${SOURCE_FILES})

add_test(SmartPointerTests ${CMAKE_BINARY_DIR}/SmartPointerTests)

target_link_libraries (SmartPointerTests DataStructures gtest gtest_main gmock_main )
install(TARGETS SmartPointerTests DESTINATION ${SMART_POINTER_INSTALL_BIN_DIR})
