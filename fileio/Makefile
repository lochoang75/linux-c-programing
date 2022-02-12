CC=gcc
FLAGS="-Wall"
.PHONY= clean all

copy: get_num.o error_functions.o 
	${CC} ${FLAGS} -o copy copy.c -I ../lib/ get_num.o error_functions.o

get_num.o:
	${CC} ${FLAGS} -c ../lib/get_num.c

error_functions.o:
	${CC} ${FLAGS} -c ../lib/error_functions.c

clean:
	rm -rf copy
	rm -rf get_num.o
	rm -rf error_functions.o
