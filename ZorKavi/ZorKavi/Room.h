#ifndef __ROOM_H_
#define __ROOM_H_


#include <string>
#include <list>
#include "Entity.h"
#include "Exit.h"

using namespace std;

class Item;
class Exit;

class Room : public Entity
{
	public:
			Room(char*, char*);
			~Room();

			void Look() const;
			Exit* GetExit(const string&) const;


};


#endif