#include "ex1.h"

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};
struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n",who->name);
	printf("\tAge: %d\n",who->age);
	printf("\tHeight: %d\n",who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc,char *argv[])
{
	//make two people structures
	struct Person *joe = Person_create(
		"Joe Alex", 32, 64, 140);

	struct Person *frank = Person_create(
		"Frank Blank", 20, 72, 180);

	// print their mem location
	printf("Joe is at memory location %p:\n",joe);
	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	// make every age 30 years
	joe->age += 30;
	joe->height -= 3;
	joe->weight == 45;
	Person_print(joe);

	frank->age += 30;
	frank->weight += 20;
	Person_print(frank);

	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}