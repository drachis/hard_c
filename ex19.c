#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"

int Monster_attack(void *self, int damage)
{
	Monster *monster = self;
	printf("You attack %s!\n",monster->_(description));
	
	monster->hit_points -= damage;
	
	if(monster->hit_points > 0) {
		printf("It is still alive.\n");
		return 0;
	} else {
		printf("It's dead Jim\n");
		return 1;
	}
}

int Monster_init(void *self)
{
	Monster *monster = self;
	monster->hit_points = 10;
	return 1;
}

Object MonsterProto = {
	.init = Monster_init,
	.attack = Monster_attack,
};

void *Room_move(void *self, Direction direction)
{
	Room *room = self;
	Room *next = NULL;
	char *dir = NULL;
	if(direction == NORTH && room->north){
		dir = "north";
		next = room->north;
	} else if(direction == SOUTH && room->south){
		dir = "south";
		next = room->south;
	} else if(direction == EAST && room->east){
		dir = "east";
		next = room->east;
	} else if(direction == WEST && room->west){
		dir = "west";
		next = room->west;
	} else {
		printf("That way is blocked");
		next = NULL;
	}
	
	if(next) {
		printf("You move %s into:\n",dir);
		next->_(describe)(next);
	}
	
	return next;
}

 int Room_attack(void *self, int damage)
 {
	Room *room = self;
	Monster *monster = room->bad_guy;
	
	if(monster) {
		monster->_(attack)(monster, damage);
		return 1;
	} else {
		printf("You attack the darkness and nothing more.\n");
		return 0;
	}
 }
 
 Object RoomProto = {
	.move =  Room_move,
	.attack = Room_attack
};

void *Map_move(void *self, Direction direction)
{
	Map *map = self;
	Room *location = map->location;
	Room *next = NULL;
	
	next = location->_(move)(location, direction);
	
	if(next) {
		map->location = next;
	}
	
	return next;
}

int Map_attack(void *self, int damage)
{
	// warning potential syntax error type* var not type *var
	Map* map = self;
	Room *location = map->location;
	
	return location->_(attack)(location,damage);
}

int Map_init(void *self)
{
	Map *map = self;
	
	// make some rooms for a small map
	
	Room *hall =  NEW(Room,"The great Hall lined with finery");
	Room *throne = NEW(Room, "The Iron throne forged from a hundered swords");
	Room *arena = NEW(Room, "Bloodstained arena with Minotaur");
	Room *kitchen = NEW(Room, "You survey the kitchem and pick up a sharp knife");
	
	// no arena is complete without a monster, but one there
	arena->bad_guy = NEW(Monster, "Corrupted minotuar");
	
	//setup the map rooms
	
	hall->north = throne;
	
	throne->west = arena;
	throne->east = kitchen;
	throne->south = hall;
	
	arena->east = throne;
	kitchen->west = throne;
	
	//your adventure beigns in the hall
	map->start = hall;
	map->location = hall;
	
	return 1;
}

Object MapProto = {
	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack,
};

int process_input(Map *game)
{
	printf("\n>");
	
	char ch = getchar();
	getchar(); //eat [ENTER]
	
	int damage = rand() % 4;
	
	switch(ch) {
		case -1:
			printf("You awaken, your body hangs in the air\n\
Reality coalesces around you and you see the console once more,\n\
Hello User.\n");
			return 0;
			break;

		case 'n':
			game->_(move)(game, NORTH);
			break;
			
		case 's':
			game->_(move)(game, SOUTH);
			break;
		
		case 'e':
			game->_(move)(game, EAST);
			break;
		
		case 'w':
			game->_(move)(game, WEST);
			break;
		
		case 'a':
			game->_(attack)(game, damage);
			break;
		
		case 'l':
			printf("You see paths:\n");
			if(game->location->north) printf("NORTH\n");
			if(game->location->south) printf("SOUTH\n");
			if(game->location->east) printf("EAST\n");
			if(game->location->west) printf("WEST\n");
			break;
			
		default:
			printf("I'm sorry you can't do %d Jim\n",ch);
	}
		
	return 1;
}

int main(int argc, char *argv[])
{
	//simple way to setup randomness	
	srand(time(NULL));
	
	//map out map to work with
	Map *game = NEW(Map, "Grand hall of the Minotaur.");
	
	printf("You enter the ");
	game->location->_(describe)(game->location);
	
	while(process_input(game)) {
	}
	
	return 0;
}