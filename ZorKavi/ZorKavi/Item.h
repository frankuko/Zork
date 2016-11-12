#ifndef __ITEM_H_
#define __ITEM_H_


#include <string>
#include "Entity.h"
class Room;

enum ItemType 
{
	COMMON,
	WEAPON,
	ARMOUR

};

enum ItemRarity
{
	STANDARD,
	RARE,
	EPIC
};

class Item : public Entity
{
	Item(const char*, const char*, Entity* parent, ItemType = COMMON, ItemRarity = STANDARD);
	~Item();

	void Look() const;
	int GetValue() const;

	ItemType type;
	ItemRarity rarity;


};


#endif