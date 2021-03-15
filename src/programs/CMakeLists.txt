set(EVEN_ODD_PRINTER_FILES EvenOddPrintingThreads.cpp)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(evenOddPrinter ${EVEN_ODD_PRINTER_FILES})
install(TARGETS evenOddPrinter RUNTIME DESTINATION bin)


add_executable(max-sum-subarray max-sum-subarray.cpp)
#add_executable(kth-largest kth-largest.cpp)
add_executable(quick_sort quick_sort.cpp)
add_executable(stock_buy_sell_once stock_buy_sell_once.cpp)

add_executable(reinterprit_cast reinterprit_cast.cpp)
add_executable(carRental car-rental.cpp)
add_executable(copyMove copy-vs-move.cpp)

add_subdirectory(multithreading)
add_subdirectory(leetcode)
add_subdirectory(dynamic_programming)
