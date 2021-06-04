CC=gcc
CFLAGS=-W -Wall -ansi
LDFLAGS= cell.h
DEPS= cell.h
OBJ= cell.o
EXEC=$1

all: $(EXEC)

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(DFLAGS)

$(EXEC): $(EXEC).c $(OBJ)
		$(CC) -o $@ $^ $(LDFLAGS)

clean:
		rm -rf *.o

mrproper: clean
		rm -rf $(EXEC)