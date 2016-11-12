#include <iostream>
#include "Item.h"
#include "Room.h"


Room::Room(const char* name, const char* description):
Entity(name,description,NULL)
{
	//TODO TIPO ROOM
}

Room::~Room() 
{

}


void Room::Look() const 
{

	cout << "\n" << name << "\n";
	cout << description;
}