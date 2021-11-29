CC=gcc

all: proj

proj:proj.o libarith.a
	$(CC) -lm -o proj proj.o -larith -L.

proj.o: proj.c
	$(CC) -c -o proj.o proj.c


clean:
	rm -rf *.o proj

