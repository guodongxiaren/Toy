CC = gcc
OBJS = server client

all: $(OBJS)

server: server.c  sock_service.o err_exit.o  
	$(CC) $^ -o bin/server 
client:client.c  sock_service.o err_exit.o
	$(CC) $^ -o bin/client
sock_service.o: sock_service.c
	$(CC) $< -c 
err_exit.o:err_exit.c
	$(CC) $< -c
#do_it.o:do_it.c 
	#gcc do_it.c -c 

.PHONY: love clean
clean:
	rm *.o
love:
	rm -f bin/*
