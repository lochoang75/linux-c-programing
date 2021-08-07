.PHONY:
	clean
	all

all: client server

client:
	gcc -Wall client.c -o client -lpthread

server:
	gcc -Wall server.c -o server -lpthread

clean:
	rm -rf client
	rm -rf server