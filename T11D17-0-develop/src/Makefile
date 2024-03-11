CC=gcc
CFLAGS= -Wall -Werror -Wextra

all: door_struct


door_struct: door_struct.h dmanager_module.c
	$(CC) $(CFLAGS) dmanager_module.c -o ../build/Quest_1

dmanager_module.o: door_struct.h dmanager_module.c
	$(CC) -c $(CFLAGS) dmanager_module.c 


clean: 
	rm -rf ../Quest_1


rebuild: clean all