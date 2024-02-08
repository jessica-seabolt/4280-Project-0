### Jessica Seabolt 4280 Project 0 ###

CC = gcc
CFLAGS = -Wall -g
TARGET = P0

OBJS = main.o tree.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c node.h tree.h
	$(CC) $(CFLAGS) -c main.c

tree.o: tree.c node.h tree.h
	$(CC) $(CFLAGS) -c tree.c

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean