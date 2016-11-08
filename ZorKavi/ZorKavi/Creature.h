#ifndef __CREATURE_H_
#define __CREATURE_H_

#include <string>
#include "Entity.h"
#include <vector>

using namespace std;

class Room;

class Creature : public Entity
{
public:
	//Methods
	Creature(char *, char *, Room*);
	virtual ~Creature();
	virtual void Look(const vector<string> & ) const;
	virtual void Update();

	//Members
	Room* actualRoom;
};

#endif
