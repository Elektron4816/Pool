CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: ../../build/Quest_3 ../../build/Quest_5 ../../build/Quest_6

../../build/Quest_3: main_executable_module.o decision.o data_process.o  data_stat.o data_io.o
	$(CC) $(CFLAGS) main_executable_module.o decision.o data_process.o data_io.o data_stat.o -o ../../build/Quest_3

main_executable_module.o: main_executable_module.c ../data_libs/data_stat.h ../data_libs/data_io.h ../yet_another_decision_module/decision.h
	$(CC) -c $(CFLAGS) main_executable_module.c ../data_libs/data_stat.c ../data_libs/data_io.c ../yet_another_decision_module/decision.c		



data_io.o: ../data_libs/data_io.h ../data_libs/data_io.c
	$(CC) -c $(CFLAGS) ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.h ../data_libs/data_stat.c
	$(CC) -c $(CFLAGS) ../data_libs/data_stat.c

data_process.o: ../data_module/data_process.h ../data_module/data_process.c
	$(CC) -c $(CFLAGS) ../data_module/data_process.c

decision.o: ../yet_another_decision_module/decision.h ../yet_another_decision_module/decision.c
	$(CC) -c $(CFLAGS) ../yet_another_decision_module/decision.c

data_stat.a: data_stat.o
	ar rc data_stat.a data_stat.o

../../build/Quest_5: main_executable_module.o decision.o data_process.o  data_stat.a data_io.o
	$(CC) $(CFLAGS) main_executable_module.o decision.o data_process.o data_io.o data_stat.a -o ../../build/Quest_5

build_with_static: ../../build/Quest_5

data_process.so: data_process.o data_stat.o
	$(CC) -c -fPIC ../data_module/data_process.c ../data_libs/data_stat.c
	$(CC) -shared -o data_process.so data_process.o data_stat.o


../../build/Quest_6: main_executable_module.o decision.o data_process.o  data_process.so data_io.o
	$(CC) $(CFLAGS) main_executable_module.o decision.o data_process.o data_io.o data_process.so -o ../../build/Quest_6 -Wl,-rpath

build_with_dynamic: ../../build/Quest_6

clean: 
	rm -rf *.o *.so *.a ../../build/Quest_3 ../../build/Quest_5 ../../build/Quest_6

rebuild: clean all