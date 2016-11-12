#include <iostream>
#include "Entity.h"
#include "Creature.h"
#include "Room.h"
#include "Item.h"
#include "World.h"

World::World() 
{
	//First Room (1-1)
	Room * room11 = new Room("Entrace of the grotto", "You see a bonfire blocking the entrace of the next room at the north. Obviously, fire kills you. Also, you notice a Pot next to the fire.");

	//Second Room (2-1)
	Room * room21 = new Room("Decision Room", "There are 3 exits. The left one is blocked by a giant rock, the north one is a lake and the right one is an old bridge. Two torches iluminate the room");

	//Room in the left (2-2)
	Room * room22 = new Room("Goblin's Hut", "There is a enormous goblin with a big of iron");

	//Room in the right (2-3)
	Room * room23 = new Room("Sacred Room", "In the middle of the room something is glowing, you don't know what to do");

	//Room in the north, aka Third Room (3-1)
	Room * room31 = new Room("Dark Room", "You cannot see nothing, but you can notice the presence of something evil");

	//Fourth Room (4-1)
	Room * room41 = new Room("Decision Room", "There are 3 chests in the middle of the room, they all have a keyhole in it. You can see the exit of the grotto.");


}

World::~World()
{

}

bool World::Command(vector<string> & args) 
{
	return false;
}

void World::Gameloop() 
{

}


