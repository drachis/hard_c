#include <stdio.h>

int main(int argc, char *argv[])
{
	int x = 3;
	int n = 2;
	
	x = x & ~n;
	printf("%i\n",x);
}