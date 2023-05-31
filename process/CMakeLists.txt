add_executable(mem_segments mem_segments.c)
add_executable(test_env change_environment.c)
target_link_libraries(mem_segments PRIVATE ${LIB_ERROR_HEADER})
target_link_libraries(test_env ${LIB_ERROR_HEADER})