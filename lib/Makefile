CC = gcc
OBJS = sock_service.o err_exit.o
ALL: $(OBJS)
	
%.o:%.c
	$(CC) -c $<
clean:
	rm -f $(OBJS)
