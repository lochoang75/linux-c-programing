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

seek_append: get_num.o error_functions.o
	${CC} ${FLAGS} -o seek_append seek_append.c -I ../lib/ get_num.o error_functions.o

atomic_append: get_num.o error_functions.o
	${CC} ${FLAGS} -o atomic_append atomic_append.c -I ../lib get_num.o error_functions.o

dup_custom: get_num.o error_functions.o
	${CC} ${FLAGS} -o dup_custom dup_custom.c -I ../lib get_num.o error_functions.o

dup2_custom: get_num.o error_functions.o
	${CC} ${FLAGS} -o dup2_custom dup2_custom.c -I ../lib get_num.o error_functions.o

all: copy seek_io custom_tee custom_cp seek_append atomic_append dup_custom dup2_custom

get_num.o:
	${CC} ${FLAGS} -c ../lib/get_num.c

error_functions.o:
	${CC} ${FLAGS} -c ../lib/error_functions.c

clean:
	rm -rf copy
	rm -rf seek_io
	rm -rf custom_tee
	rm -rf custom_cp
	rm -rf seek_append
	rm -rf atomic_append
	rm -rf dup_custom
	rm -rf dup2_custom
	rm -rf get_num.o
	rm -rf error_functions.o
