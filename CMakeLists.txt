
cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

set(CMAKE_BUILD_TYPE DEBUG)

set(CMAKE_CXX_FLAGS "-std=c++11")

add_library(utils SHARED timer.cpp
                          profiler.cpp
                          logger.cpp
                          systemtime.cpp
                          getfilename_with_timestamp.cpp
                          getfilebasename.cpp
                          getfileextension.cpp
                          getbasepath.cpp
                          executablename.cpp
                          integer_sequence.cpp
                          console_print.cpp)

add_executable(test test.cpp)
add_executable(test_console_print test_console_print.cpp)

target_link_libraries(test utils)
target_link_libraries(test_console_print utils)
