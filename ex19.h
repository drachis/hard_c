#ifndef _ex19_h
#define _ex19_h

#include "object.h"

struct Moster {
	Object proto;
	int hit_points;
};

typedef struct Monster monster;

int Moster_attack(void *self,int damage);
int Monster_init(void *self);

struct Room {
	Object proto;
	
	Moster *bad_guy;
	
	struct Room *north;
	struct Room *south;
	struct Room *east;
	struct Room *west;
};

typedef struct Room Room;

void *Room_move(void *self, Direction direction);
int Room_attack(void *self, int damage);
int Room_init(void *self);

struct Map {
	Object proto;
	Room *start;
	Room *location;
};

typedef struct Map Map;

void *Map_map(void *self, Direction direction);
int Map_attack(void *self, int damage);
int Map_init(void *self);

#endif