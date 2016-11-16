#include "Item.h"

	Item::Item(char * name, char * descrption, Entity * parent, ItemType item_type, ItemRarity rarity) :
		Entity(name, descrption,parent), item_type(item_type), rarity(rarity)
	{
		type = ITEM;
	}

	Item::~Item()
	{

	}

	void Item::Look() const
	{


	}

	int Item::GetValue() const
	{
		return 0;
	}