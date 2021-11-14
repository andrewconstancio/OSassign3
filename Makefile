CC=gcc
CFLAGS=-I.

hellomake: part1.o
	$(CC) -o part1 part1.o