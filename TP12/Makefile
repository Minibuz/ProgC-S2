CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=
DEPS=node.h hashTable.h
OBJ=node.o hashTable.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)