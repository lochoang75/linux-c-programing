add_executable(t_sysconf t_sysconf.c)
target_link_libraries(t_sysconf ${LIB_ERROR_HEADER})

add_executable(t_pathconf t_pathconf.c)
target_link_libraries(t_pathconf ${LIB_ERROR_HEADER})