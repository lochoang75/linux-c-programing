set(lib_src src/error_functions.c src/get_num.c)
add_library(${LIB_ERROR_HEADER} STATIC ${lib_src})