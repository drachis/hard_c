#include "ex18.h"

// die from ex 17
void die (const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	
	exit(1);
}

/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	//idea for an optimazation, reduce the sort range by 1 every pass
	/*
	 * for a list 1 6 3 2 on the first pass in the sub loop 
	 * 6 would migrate to its final position and that index could be removed
	 * this might help optimize the sort slightly( 
	 * other sorts may be much be much better in O(n) terms.
	 */
	int temp = 0;
	int i = 0;
	int j = 0;
	int *target = malloc(count * sizeof(int));
	
	if(!target) die("Memory error.");
	
	memcpy(target, numbers, count * sizeof(int));
	
	for(i = 0; i < count; i++) {
		for(j = 0;j < count - 1; j++) {
			if(cmp(target[j],target[j+1]) > 0){
				/* index pre sort, 
				 *printf("%i pre: [%i] %i , [%i] %i\n",
				 *	i,
				 *	j+1,
				 *	target[j+1],
				 *	j,
				 *	target[j]
				 *	);
				 */
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
				/*index post sort
				 *printf("%i pst: [%i] %i , [%i] %i\n",
				 *	i,
				 *	j+1,
				 *	target[j+1],
				 *	j,
				 *	target[j]
				 *	);
				 */
			}
		}
	}
	
	return target;
}

int sorted_order(int a, int b)
{
	return a - b;
}

int reverse_order(int a, int b)
{
	return b - a;
}

int strange_order(int a, int b)
{
	if(a == 0 || b == 0) {
		return 0;
	} else {
		return a % b;
	}
}

int other_order(int b, int c){
	if ((c+b)%(b-c) > b){
		return c;
	} else {
		return b;
	}	
}

void test_sorting(int *numbers, int count, compare_cb cmp)
{
	int i = 0;
	int *sorted = bubble_sort(numbers, count, cmp);
	
	if(!sorted) die ("Failed to sort as requested.");
	
	for(i = 0; i < count; i ++) {
		printf("%d ", sorted[i]);
	}
	
	printf("\n");
	
	unsigned char *data = (unsigned char *)cmp;
	for(i = 0; i < 25; i++){
		printf("%02x:", data[i]);
	}
	printf("\n");
	
	free(sorted);
}

int main(int argc, char *argv[])
{
	if(argc < 2) die("USAGE: ex18 9 8 5 3 10");
	
	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;
	
	int *numbers = malloc(count * sizeof(int));
	if(!numbers) die("Memory error");
	
	for( i = 0; i < count; i++) {
		numbers[i] = atoi(inputs[i]);
	}
	
	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);
	test_sorting(numbers, count, other_order);
	
	free(numbers);
	
	return 0;
}