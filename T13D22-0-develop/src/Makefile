CC= gcc
CFLAG= -Wall -Werror -Wextra

all: cipher logging_cipher
cipher: cipher.o logger.o
	$(CC) $(CFLAG) cipher.o logger.o -o ../build/cipher
cipher.o: cipher.c
	$(CC) -c $(CFLAG) -o cipher.o cipher.c
logger.o: logger.h log_levels.h logger.c
	$(CC) -c $(CFLAG) -o logger.o logger.c
logging_cipher: cipher.o logger.o
	$(CC) $(CFLAG) cipher.o logger.o -o ../build/logging_cipher

clean:
	rm -rf *.o
rebuild: clean all