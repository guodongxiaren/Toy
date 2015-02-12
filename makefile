all:server client

server: server.h server.c 
	gcc server.c  -o bin/server
client:client.c
	gcc client.c -o bin/client
#do_it.o:do_it.c 
	#gcc do_it.c -c 
