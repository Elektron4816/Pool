CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: state_sort

state_sort: state.o state_sort.o
	$(CC) $(CFLAGS) state.o state_sort.o -o ../build/Quest_1
state.o: state.h state.c
	$(CC) -c $(CFLAGS) -o state.o state.c
state_sort.o: state.h state.c 
	$(CC) -c $(CFLAGS) -o state_sort.o state_sort.c

clean:
	rm -rf *.o
rebuild: clean all