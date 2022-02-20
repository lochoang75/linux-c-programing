CC=gcc
FLAGS=-Wall
.PHONY= clean all

copy: get_num.o error_functions.o 
	${CC} ${FLAGS} -o copy copy.c -I ../lib/ get_num.o error_functions.o

seek_io: get_num.o error_functions.o
	${CC} ${FLAGS} -o seek_io seek_io.c -I ../lib/ get_num.o error_functions.o

custom_tee: get_num.o error_functions.o
	${CC} ${FLAGS} -o custom_tee custom_tee.c -I ../lib/ get_num.o error_functions.o

custom_cp: get_num.o error_functions.o
	${CC} ${FLAGS} -o custom_cp custom_cp.c -I ../lib/ get_num.o error_functions.o

all: copy seek_io custom_tee custom_cp

get_num.o:
	${CC} ${FLAGS} -c ../lib/get_num.c

error_functions.o:
	${CC} ${FLAGS} -c ../lib/error_functions.c

clean:
	rm -rf copy
	rm -rf seek_io
	rm -rf custom_tee
	rm -rf custom_cp
	rm -rf get_num.o
	rm -rf error_functions.o
