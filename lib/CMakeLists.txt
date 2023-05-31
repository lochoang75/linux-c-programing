set(lib_SOURCES src/error_functions.c src/get_num.c src/log.c)
add_library(${LIB_ERROR_HEADER} STATIC ${lib_SOURCES})