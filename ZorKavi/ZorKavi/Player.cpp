#include <iostream>
#include "Room.h"
#include "Item.h"

#include "Player.h"

Player::Player( char* name,  char* desc, Room* room):
	Creature(name,desc,room)
{

}

Player::~Player()
{

}

void Player::Look() const
{

}