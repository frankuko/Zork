#include <iostream>
#include "Item.h"
#include "Room.h"


Room::Room(char* name, char* description):
Entity(name,description,NULL)
{
	type = ROOM;

}

Room::~Room() 
{

}


void Room::Look() const 
{

	cout << "\n" << name << "\n";
	cout << description;
}