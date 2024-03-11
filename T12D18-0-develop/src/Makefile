CC=gcc
CFLAGC= -Wall -Wextra -Werror

all: print_module

main_module_entry_point.o: print_module.h main_module_entry_point.o
	$(CC) -c $(CFLAGC) -o main_module_entry_point.o main_module_entry_point.c

print_module.o: print_module.h print_module.c
	$(CC) -c $(CFLAGC) -o print_module.o print_module.c


print_module: main_module_entry_point.o print_module.o
	$(CC) $(CFLAGC) main_module_entry_point.o print_module.o -o ../build/Quest_1

clean: rm -rf *.o ../build/Quest_1

rebuild: clean all