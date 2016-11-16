#include <iostream>
#include "Room.h"
#include "Item.h"

#include "Player.h"

Player::Player( char* name,  char* desc, Room* room):
	Creature(name,desc,room)
{
	type = PLAYER;
}

Player::~Player()
{

}

void Player::Look(const vector<string> & args) const
{
	
	if (args.size() > 1)
	{
		for (list<Entity*>::const_iterator it = parent->entities.begin(); it != parent->entities.cend(); ++it)
		{
			//look place
			if ((*it)->name.compare(args[1]) == 0)
			{
				(*it)->Look();
				return;
			}

		}

	}
	else
	{
		parent->Look();
	}
}

void Player::Inventory() const
{
	list<Entity*> items;
	FindAll(ITEM, items);

	if (items.size() == 0)
	{
		cout << "\nYou do not own any item.\n";
		return;
	}

	for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
	{

		(*it)->Look();
	}


}

bool Player::Go(const vector<string> & args)
{
	return false;
}

bool Player::Take(const vector<string> & args)
{
	return false;
}