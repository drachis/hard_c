#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include <assert.h>

void Object_destroy(void *self)
{
	Object *obj = self;
	
	if (obj) {
		if (obj->description) free(obj->description);
		free(obj);
	}
}

void Object_describe(void *self)
{
	Object *obj = self;
	printf("%s. \n",obj ->description);
}

int Object_init(void *self)
{
	// beep boop doing nothing
	return 1;
}

void *Object_move(void *self, Direction direction);
{
	printf("You can't go in that direction.\n");
	return NULL;
}

int Object_attack(void *self, int damage)
{
	printf("You can't attack that.\n");
	return 0;
}
int *Object_new(size_t size, Object proto, char *description)
{
	//setup the default funtions in case they aren't set
	if(!proto.init) proto.init = Object_init;
	if(!proto.describe) proto.describe = Object_describe;
	if(!proto.destroy) proto.destory = Object_destroy;
	if(!proto.attack) proto.attack = Object_attack;
	if(!proto.move) proto.move = Object_move;
	
	//create a size one struct
	//point a different pointer at it to "cast" it
	
	Object *el = calloc(1,size);
	*el = proto;
	
	// copy the description over
	el->description = strdup(description);
	
	// initialize it with whatever init we were given
	if(!el->init(el)) {
		// looks like it didn't initialize properly
		el->destroy(el);
		return NULL;
	} else {
		// all done, we make an object of any type
		return el;
	}
}

}
v