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

shared_mem: shm.c
	${CC} ${FLAGS} -o shared_mem shm.c

mmap_write: mmap-write.c
	${CC} ${FLAGS} -o mmap_write mmap-write.c
mmap_read: mmap-read.c
	${CC} ${FLAGS} -o mmap_read mmap-read.c

pipe: pipe.c
	${CC} ${FLAGS} -o pipe pipe.c

all: getopt_long fork fork-exec zombie sigchld thread-create thread-create2 tsd_app shared_mem mmap_write mmap_read pipe

clean:
	rm -rf getopt_long
	rm -rf fork
	rm -rf fork-exec
	rm -rf zombie
	rm -rf sigchld
	rm -rf thread-create
	rm -rf thread-create2
	rm -rf tsd_app
	rm -rf shared_mem
	rm -rf mmap_write
	rm -rf mmap_read
	rm -rf pipe
