#include "tools.h"

void debug_array(
	char *array[],
	)
{
	int i = 0;
	int size = sizeof(array);
	for(i=0; i < size; i ++){
		printf("%i: %s\n",i,array[i]);
	}
}
