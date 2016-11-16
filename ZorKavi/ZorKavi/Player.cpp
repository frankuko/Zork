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

	for (list<Entity*>::const_iterator it = items.begin(); it != items.end(); ++it)
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

		if (item->rarity == EPIC)
		{
			cout << "\nYou can't take this item.\n";
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

void Tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ")
{
	// Skip delimiters at beginning.
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// Find first "non-delimiter".
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}


}

bool Player::Use(const vector<string> & args)
{

	vector<string> objs;
	Tokenize(args[1], objs);



	if (objs.size() == 3 && objs[1].compare("on") == 0)
	{
		string obj1 = objs[0];
		Item* item1 = (Item*)Find(obj1, ITEM);

		if (item1 == NULL)
		{
			cout << "\nThere is no item on you with that name.\n";
			return false;
		}

		string obj2 = objs[2];

		Item* item2 = (Item*)parent->Find(obj2, ITEM);
		if (item2 == NULL)
		{
			cout << "\nThere is nothing with that name to use that object.\n";
			return false;
		}

		//abrir puertas cerradas

		if (item1->item_type != KEY)
			return false;

		if (item2->item_type != BLOCK)
			return false;

		list<Entity*> exits;
		parent->FindAll(EXIT, exits);

		cout << item1->GetValue() << endl;

		delete item1;

		for (list<Entity*>::iterator it = exits.begin(); it != exits.end(); ++it)
		{
			
			((Exit*)(*it))->Unlock();


		}

		return true;
	}

	return false;
}

