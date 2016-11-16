#include "Item.h"

	Item::Item(char * name, char * descrption, Entity * parent, char* action,ItemType item_type, ItemRarity rarity) :
		Entity(name, descrption,parent), value(action), item_type(item_type), rarity(rarity)
	{
		type = ITEM;
		
	}

	Item::~Item()
	{

	}

	/*void Item::Look() const
	{
		cout << "\t" << name << endl;
		cout << "\t\t" << description << endl;

	}*/

	string Item::GetValue() const
	{
		return value;
	}