CC=gcc
CFLAGS= -Wall -Werror -Wextra
LIB= ../build/

all: s21_string.o s21_string_test.o

s21_string.o: s21_string.h s21_string.c
	$(CC) -c $(CFLAGS) s21_string.c

s21_string_test.o: s21_string_test.h s21_string_test.c
	$(CC) -c $(CFLAGS) s21_string_test.c

strlen_tests: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) -D strlen_tests s21_string.c s21_string_test.c -o ../build/Quest_1

strcmp_tests: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) -D strcmp_tests s21_string.c s21_string_test.c -o ../build/Quest_2

strcpy_tests: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) -D strcpy_tests s21_string.c s21_string_test.c -o ../build/Quest_3

strcat_tests: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) -D strcat_tests s21_string.c s21_string_test.c -o ../build/Quest_4

strchr_tests: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) -D strchr_tests s21_string.c s21_string_test.c -o ../build/Quest_5

strstr_tests: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) -D strstr_tests s21_string.c s21_string_test.c -o ../build/Quest_6


clean:
	rm -rf *.o $(LIB)Quest_1 $(LIB)Quest_2 $(LIB)Quest_3 $(LIB)Quest_4 $(LIB)Quest_5 $(LIB)Quest_6 $(LIB)Quest_7


rebuild: clean all