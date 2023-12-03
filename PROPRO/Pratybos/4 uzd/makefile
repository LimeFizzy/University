CC = gcc
CFLAGS = -Wall -Werror

TARGET = tests

$(TARGET): unit.o func.o
	$(CC) $(CFLAGS) -o $(TARGET) unit.o func.o

unit.o: unit.c func.h
	$(CC) $(CFLAGS) -c unit.c

func.o: func.c func.h
	$(CC) $(CFLAGS) -c func.c

clean:
	rm -f $(TARGET) *.o
