all:
	clear
	rm -f ./bin/ex19
	CFLAGS=-Wall
	cc ex19.c -g -o ./bin/ex19
	echo "\nCompile Complete,\n Executing:"
	./bin/ex19
	echo "\nValgrind Go!:"
	valgrind ./bin/ex19
cc:
	clear
	rm -f ./bin/ex19
	CFLAGS=-Wall
	cc ex19.c -g -o ./bin/ex19
clang:
	clear
	rm -f ./bin/ex19
	CFLAGS=-Wall
	clang ex19.c -o ./bin/ex19_clang
	./bin/ex19_clang
clean:
	rm -f ./bin/*

ex19:
	clear
	rm -f ./bin/ex19
	CFLAGS=-Wall
	cc ex19.c -g -o ./bin/ex19
	echo "\nCompile Complete,\n Executing:"
	./bin/ex19
	echo "\nValgrind Go!:"
	valgrind ./bin/ex19