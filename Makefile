all:
	rm -f ./bin/ex1
	CFLAGS=-Wall
	cc ex1.c -g -o ./bin/ex1
	clear
	echo "\nCompile Complete,\n Executing:"
	./bin/ex1
	
	echo "\nValgrind Go!:"
	valgrind ./bin/ex1
	

clean:
	rm -f ./bin/ex1
	
phil:
	
	rm -f ./bin/p1
	CFLAGS=Wall
	cc p1.c -g -o ./bin/p1
	echo "\nCompile Complete\n"
	./bin/p1
	echo "\nValgrind Go!:\n"
	valgrind ./bin/p1
	clear
