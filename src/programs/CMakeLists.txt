set(EVEN_ODD_PRINTER_FILES EvenOddPrintingThreads.cpp)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(evenOddPrinter ${EVEN_ODD_PRINTER_FILES})
install(TARGETS evenOddPrinter RUNTIME DESTINATION bin)
