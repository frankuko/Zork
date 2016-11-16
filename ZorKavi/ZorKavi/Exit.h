#ifndef __EXIT_H_
#define __EXIT_H_

#include <iostream>
#include "Entity.h"
#include "Room.h"

using namespace std;

class Room;

enum Direction
{
	N,
	S,
	E,
	W
};

class Exit : public Entity
{
	public:
			Exit(char * , char *, Room * , Room * ,Direction);
			~Exit();
			void Look() const;
			string GetDirection() const;
			void ChangeDirection();
			

			bool closed;
			bool locked;
			//Entity* key;

			//Only room destination, origin will be the parent
			Room * destination;


			//Initial Direction of the exit
			Direction direction;


};

#endif
