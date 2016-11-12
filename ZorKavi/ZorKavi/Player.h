#ifndef __PLAYER_H_
#define __PLAYER_H_


#include "Creature.h"

using namespace std;


class Player : public Creature
{
	Player(char*, char*, Room*);
	~Player();

	void Look() const;



};

#endif