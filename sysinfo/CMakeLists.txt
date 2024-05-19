add_executable(procfs_pidmax procfs_pidmax.c)
target_link_libraries(procfs_pidmax ${LIB_ERROR_HEADER})

add_executable(t_uname t_uname.c)
target_link_libraries(t_uname ${LIB_ERROR_HEADER})

add_executable(proc_listing proc_listing.c)
target_link_libraries(t_uname ${LIB_ERROR_HEADER})