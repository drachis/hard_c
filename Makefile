all:
	clear
	rm -f ./bin/ex18
	CFLAGS=-Wall
	cc ex18.c -g -o ./bin/ex18
	echo "\nCompile Complete,\n Executing:"
	./bin/ex18
	echo "\nValgrind Go!:"
	valgrind ./bin/ex18

clean:
	rm -f ./bin/ex18

phil:
	
	rm -f ./bin/p1
	CFLAGS=Wall
	cc p1.c -g -o ./bin/p1
	echo "\nCompile Complete\n"
	./bin/p1
	echo "\nValgrind Go!:\n"
	valgrind ./bin/p1