#include "Item.h"

	Item::Item(const char * name, const char * descrption, Entity * parent, ItemType type, ItemRarity rarity) :
		Entity(name, descrption,parent), type(type), rarity(rarity)
	{
		//definir tipo
	}

	Item::~Item()
	{

	}

	void Item::Look() const
	{


	}