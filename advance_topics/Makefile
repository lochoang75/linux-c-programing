CC=gcc
FLAGS= -Wall
.PHONY= clean all

getopt_long: getopt_long.c
	${CC} ${FLAGS} -o getopt_long getopt_long.c

fork: fork.c
	${CC} ${FLAGS} -o fork fork.c
fork-exec: fork-exec.c
	${CC} ${FLAGS} -o fork-exec fork-exec.c

zombie: zombie.c
	${CC} ${FLAGS} -o zombie zombie.c
sigchld: sigchld.c
	${CC} ${FLAGS} -o sigchld sigchld.c

thread-create: thread_create.c
	${CC} ${FLAGS} -o thread-create thread_create.c -lpthread
thread-create2: thread_create2.c
	${CC} ${FLAGS} -o thread-create2 thread_create2.c -lpthread
tsd_app: tsd.c
	${CC} ${FLAGS} -o tsd_app tsd.c -lpthread -std=c99

all: getopt_long fork fork-exec zombie sigchld thread-create thread_create2 tsd_app

clean:
	rm -rf getopt_long
	rm -rf fork
	rm -rf fork-exec
	rm -rf zombie
	rm -rf sigchld
	rm -rf thread-create
	rm -rf thread-create2
	rm -rf tsd_app
