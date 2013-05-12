all:
	clear
	rm -f ./bin/ex1
	CFLAGS=-Wall
	cc ex1.c -g -o ./bin/ex1
	echo "\nCompile Complete,\n Executing:"
	./bin/ex1
	echo "\nValgrind Go!:"
	valgrind ./bin/ex1
	

clean:
	rm -f ./bin/ex1
	rm -f ./bin/db.dat
phil:
	
	rm -f ./bin/p1
	CFLAGS=Wall
	cc p1.c -g -o ./bin/p1
	echo "\nCompile Complete\n"
	./bin/p1
	echo "\nValgrind Go!:\n"
	valgrind ./bin/p1

ex17:
	clear
	rm -f ./bin/ex1
	cc -Wall -g    ex1.c   -o ./bin/ex17
	./bin/ex17 ./bin/db.dat c
	./bin/ex17 ./bin/db.dat s 1 zed zed@zedshaw.com
	./bin/ex17 ./bin/db.dat s 2 frank frank@zedshaw.com
	./bin/ex17 ./bin/db.dat s 3 joe joe@zedshaw.com

	./bin/ex17 ./bin/db.dat l
	./bin/ex17 ./bin/db.dat d 3
	./bin/ex17 ./bin/db.dat l
	./bin/ex17 ./bin/db.dat g 2

	valgrind --leak-check=yes ./bin/ex17 ./bin/db.dat g 2
