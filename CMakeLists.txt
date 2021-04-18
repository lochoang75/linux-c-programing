cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "./build")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "./build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./build")

project(LinuxSampleSource)

add_subdirectory(Lib)
add_executable(copy fileio/copy.c)
target_link_libraries(copy error_functions)
target_link_libraries(copy get_num)

add_executable(seek_io fileio/seek_io.c)
target_link_libraries(seek_io error_functions)
target_link_libraries(seek_io get_num)
