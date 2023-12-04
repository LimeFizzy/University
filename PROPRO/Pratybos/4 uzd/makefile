CC = gcc
CFLAGS = -Wall -Werror

main:
	$(CC) -o main main.c func.c
	./main 

test: unit.o func.o
	$(CC) $(CFLAGS) -o test unit.o func.o
	./test

clean:
	rm -f test main *.o
