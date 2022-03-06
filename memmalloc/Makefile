CC=gcc
FLAGS=-Wall
.PHONY= clean all

num_allocs: get_num.o error_functions.o
	${CC} ${FLAGS} -o num_allocs free_and_sbrk.c -I ../lib get_num.o error_functions.o

all: num_allocs 

get_num.o:
	${CC} ${FLAGS} -c ../lib/get_num.c

error_functions.o:
	${CC} ${FLAGS} -c ../lib/error_functions.c

clean:
	rm -rf num_allocs
	rm -rf get_num.o
	rm -rf error_functions.o
