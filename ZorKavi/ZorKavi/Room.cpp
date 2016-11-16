#include <iostream>
#include "Item.h"
#include "Exit.h"
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
	cout << "-------------------------------" << endl;

	cout << "ACTUAL ROOM" << endl;

	cout << "\n" << name << "\n";
	cout << description;

	cout << "\n-------------------------------" << endl;

	cout << "\nITEMS:\n" << endl;

	for (list<Entity*>::const_iterator it = entities.begin(); it != entities.end(); ++it)
	{
		

		if ((*it)->type == ITEM)
		{
			Item* item = (Item*)*it;
			item->Look();
		}
	}

	cout << "-------------------------------" << endl;

	cout << "\nEXITS:\n" << endl;

	for (list<Entity*>::const_iterator it = entities.begin(); it != entities.end(); ++it)
	{

		if ((*it)->type == EXIT)
		{

			Exit* exit = (Exit*)*it;
			exit->Look();
		}
	}

	cout << "-------------------------------" << endl;
}


Exit*  Room::GetExit(const string& direction) const
{
	for (list<Entity*>::const_iterator it = entities.begin(); it != entities.end(); ++it)
	{
		if ((*it)->type == EXIT)
		{
			Exit* ex = (Exit*)*it;
			if(ex->GetDirection().compare(direction) == 0)
					return ex;
		}
	}

	return NULL;

}