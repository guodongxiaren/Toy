CC = gcc
OBJS = server client
CFLAGS = -I lib -g

vpath %.o lib
ALL: $(OBJS)

server: server.c  sock_service.o err_exit.o  
	$(CC) $(CFLAGS) $^ -o bin/server 
client: client.c  sock_service.o err_exit.o
	$(CC) $(CFLAGS) $^ -o bin/client
sock_service.o:
	cd lib;$(MAKE)
err_exit.o:
	cd lib;$(MAKE)
#sock_service.o: sock_service.c
#	$(CC) $< -c 
#err_exit.o:err_exit.c
#	$(CC) $< -c
#do_it.o:do_it.c 
#   gcc do_it.c -c 

.PHONY: love clean
clean:
	-rm -f bin/*
	cd lib;$(MAKE) clean
