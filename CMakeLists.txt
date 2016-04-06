
cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

set (CMAKE_BUILD_TYPE DEBUG)

find_package(Boost)
if (boost_found)
	include_directories(${BOOST_INCLUDE_DIR})
	add_definitions("-dhas_boost")
endif()

add_library (utils SHARED timer.cpp\\
                          logger.cpp\\
                          systemtime.cpp\\
                          getfilename_with_timestamp.cpp\\
                          getfilebasename.cpp\\
                          getfileextension.cpp\\
                          getbasepath.cpp\\
                          executablename.cpp\\
                          integer_sequence.cpp)

add_executable (test test.cpp)

target_link_libraries (test utils)
