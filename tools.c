#include "tools.h"

void print_array(
	char *array[],
	)
{
	int i = 0;
	for(i=0; i < sizeof(array); i ++){
		printf("%i: %s\n",i,array[i]);
	}
}
