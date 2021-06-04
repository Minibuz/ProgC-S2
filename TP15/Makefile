CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=-lreadline -lm
DEPS= heap.h
OBJ= heap.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)