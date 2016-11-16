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
		for (list<Entity*>::const_iterator it = parent->entities.begin(); it != parent->entities.end(); ++it)
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
		Room * r = ((Room*) (parent));
		r->Look();
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

bool Player::Go(const vector<string>& args)
{
	

	Exit* exit = ActualRoom()->GetExit(args[1]);

	if (exit == NULL)
	{
		cout << "\nThere is no exit at '" << args[1] << "'.\n";
		return false;
	}

	if (exit->locked)
	{
		cout << "\nThat exit is blocked.\n";
		return false;
	}

	cout << "\nYou take direction " << exit->GetDirection() << "...\n";

	//ChangeParent(exit->GetDestinationFrom((Room*)parent));



	//change my parent
	ChangeParent(exit->destination);

	//change exit parent
	exit->ChangeDirection();
	parent->Look();

	return true;
}

bool Player::Take(const vector<string> & args)
{

	if (args.size() == 2)
	{


		Item* item = (Item*)parent->Find(args[1], ITEM);

		if (item == NULL)
		{
			cout << "\nThere is no item here with that name.\n";
			return false;
		}

		cout << "\nYou take " << item->name << ".\n";
		item->ChangeParent(this);

	}

	return false;
}

bool Player::Drop(const vector<string> & args)
{
	if (args.size() == 2)
	{

		
		Item* item = (Item*)Find(args[1], ITEM);

		if (item == NULL)
		{
			cout << "\nThere is no item on you with that name.\n";
			return false;
		}

		cout << "\nYou drop " << item->name << "...\n";
		item->ChangeParent(parent);

		return true;
	}

	return false;
}

