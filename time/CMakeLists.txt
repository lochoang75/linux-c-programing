add_executable(calendar_time calendar_time.c)
target_link_libraries(calendar_time ${LIB_ERROR_HEADER})

add_executable(strtime strtime.c)
target_link_libraries(strtime ${LIB_ERROR_HEADER})

add_executable(process_time process_time.c)
target_link_libraries(process_time ${LIB_ERROR_HEADER})