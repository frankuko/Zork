#include <iostream>
#include "Entity.h"
#include "Creature.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Player.h"
#include "World.h"

World::World() 
{

	//ROOMS

	//First Room (1-1)
	Room * room11 = new Room("Entrace of the grotto", "You see a bonfire blocking the entrace of the next room at the north. Obviously, fire kills you. Also, you notice a Pot next to the fire.");
	Item * itemr111 = new Item("Pot", "A pot full of water",room11);

	//Second Room (2-1)
	Room * room21 = new Room("Decision Room", "There are 3 exits. The left one is blocked by a giant rock, the north one is a lake and the right one is an old bridge. Two torches iluminate the room.");
	Item * itemr211 = new Item("Torch", "A big torch",room21);
	//Item * itemr212 = new Item("Torch", "A pot full of water",room21);

	//Room in the left (2-2)
	Room * room22 = new Room("Goblin's Hut", "There is a enormous goblin with a big stick of iron");
	Creature * creature1 = new Creature("Big Goblin", "A stupid idiot globin.", room22);
	Item * itemr221 = new Item("Big Stick of Iron", "Is a stick", creature1);

	//Room in the right (2-3)
	Room * room23 = new Room("Sacred Room", "In the middle of the room something is glowing, you don't know what to do");
	Item * itemr231 = new Item("THE KEY", "There's a note with the key: YOU CAN CHOOSE ONLY ONE...",room23);

	//Room in the north, aka Third Room (3-1)
	Room * room31 = new Room("Dark Room", "You cannot see nothing, but you can notice the presence of something evil");
	Creature * creature2 = new Creature("Shadow", "A terrorific shadow.", room31);

	//Fourth Room (4-1)
	Room * room41 = new Room("Final Room", "There are 3 chests in the middle of the room, they all have a keyhole in it. You can see the exit of the grotto.");
	Item * itemr411 = new Item("Left chest", "A big chest, looks that is full of coins", room41);
	Item * itemr412 = new Item("Right chest", "A small chest, looks empty", room41);

	entities.push_back(room11);
	entities.push_back(itemr111);
	entities.push_back(room21);
	entities.push_back(itemr211);
	//entities.push_back(itemr212);
	entities.push_back(room22);
	entities.push_back(creature1);
	entities.push_back(itemr221);
	entities.push_back(room23);
	entities.push_back(itemr231);
	entities.push_back(creature2);
	entities.push_back(room31);
	entities.push_back(room41);
	entities.push_back(itemr411);
	entities.push_back(itemr412);

	//EXITS

	Exit * exit1121 = new Exit("Initial Room to Decision Room", "This exit goes from the entrance of the cave to the Decision Room",room11,room21,N);

	Exit * exit2122 = new Exit("Decision Room to Goblin's Hut", "There is a enormous bridge crossing the room. At the end of the room you can see a big hut",room21,room22,W);

	Exit * exit2123 = new Exit("Decision Room to Sacred Room", "There is a giant rock blocking the entrance. Maybe you can move it with a stick.", room21, room23,E);

	Exit * exit2131 = new Exit("Decision Room to Dark Room", "There is a small boat aside to the lake, maybe you can use it to cross it",room21,room31,N);

	Exit * exit3141 = new Exit("Dark Room to Final Room", "This exit goes to a room that looked created by the men.", room31, room41,N);

	entities.push_back(exit1121);
	entities.push_back(exit2122);
	entities.push_back(exit2123);
	entities.push_back(exit2131);
	entities.push_back(exit3141);


	player = new Player("John", "Locke", room11);

	entities.push_back(player);

	Item * item1 = new Item("Bracelet", "This a bracelet someone gave to protect you.",player);
	

	/*vector<string> args;
	args.reserve(10);

	args.push_back("Entrace of the grotto");

	player1->Look(args);*/


}

World::~World()
{
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		delete *it;

	entities.clear();
}

bool World::Command(vector<string> & args) 
{

	bool res = false;

	switch (args.size())
	{
		case 1: 
			{
				if (args[0].compare("look") == 0)
				{
					player->Look(args);
					res = true;
				}

				if (args[0].compare("inventory") == 0)
				{
					player->Inventory();
					res = true;
				}
			}

			break;

		case 2:
			{
				if (args[0].compare("look") == 0) 
				{
					player->Look(args);
					res = true;
				}

				if (args[0].compare("take") == 0)
				{
					player->Take(args);
					res = true;
				}

				if (args[0].compare("drop") == 0)
				{
					player->Drop(args);
					res = true;
				}

				if (args[0].compare("go") == 0)
				{
					player->Go(args);
					res = true;
				}

			}

			break;

		default:
			break;
	}

	return res;
}

void World::Gameloop() 
{

}


