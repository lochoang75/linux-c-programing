.PHONY:
	all
	clean
all: share_mem_mutex 		\
	semaphores_share 		\
	message_queue_share 	\
	share_anonymous_pipe 	\
	share_named_pipe		\

share_mem_mutex:
	gcc -Wall share_mem_mutex.c -o share_mem_mutex -lpthread -lrt

semaphores_share:
	gcc -Wall semaphore_share.c -o semaphores_share -lpthread

message_queue_share:
	gcc -Wall share_message_queue.c -o message_queue_share -lpthread -lrt

share_anonymous_pipe:
	gcc -Wall share_anonymous_pipe.c -o share_anonymous_pipe -lpthread

share_named_pipe:
	gcc -Wall share_named_pipe.c -o share_named_pipe -lpthread

clean:
	rm -rf share_mem_mutex
	rm -rf semaphores_share
	rm -rf message_queue_share
	rm -rf share_anonymous_pipe
	rm -rf share_named_pipe