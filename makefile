all:server client

server:server.c
	gcc server.c -o bin/server
client:client.c
	gcc client.c -o bin/client
