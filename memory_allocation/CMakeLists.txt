set(memory_allocation_SOURCES free_and_sbrk.c)

add_executable(free_and_sbrk free_and_sbrk.c)
target_link_libraries(free_and_sbrk PRIVATE ${LIB_ERROR_HEADER})