set(lib_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/error_functions.c
                ${CMAKE_CURRENT_SOURCE_DIR}/src/get_num.c
                ${CMAKE_CURRENT_SOURCE_DIR}/src/log.c
                ${CMAKE_CURRENT_SOURCE_DIR}/src/ugid_functions.c
                )
add_library(${LIB_ERROR_HEADER} STATIC ${lib_SOURCES})