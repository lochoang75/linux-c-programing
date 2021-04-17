set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "./build")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "./build")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "./build")

add_library(error_functions STATIC src/error_functions.c)
add_library(get_num STATIC src/get_num.c)
target_include_directories(error_functions PUBLIC include)
target_include_directories(get_num PUBLIC include)
