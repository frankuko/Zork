#ifndef __ROOM_H_
#define __ROOM_H_


#include <string>
#include <list>
#include "Entity.h"

using namespace std;

class Item;
//class exit

class Room : public Entity
{
	public:
			Room(const char*, const char*);
			~Room();

			void Look() const;



};


#endif