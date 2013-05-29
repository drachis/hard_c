## update before make will work with ex20

CFLAGS=-Wall

all: ex20

ex22:
	clear
	cc -Wall -g -DNDBUG -c -o ex22.o ex22.c
	cc -Wall -g -DNDBUG ex22_main.c ex22.o -o ex22_main
	./ex22_main

clean:
	rm -f ex19
	rm -f object.o