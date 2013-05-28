## update before make will work with ex20

CFLAGS=-Wall

all: ex20

ex20: dbg.h

clean:
	rm -f ex19
	rm -f object.o