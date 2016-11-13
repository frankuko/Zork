#ifndef __EXIT_H_
#define __EXIT_H_

#include "Entity.h"
#include "Room.h"

class Exit : public Entity
{
	public:
			Exit(char * , char *, Room * , Room * );
			~Exit();
			void Look() const;


			bool closed;
			bool locked;
			Entity* key;

			//Only room destination, origin will be the parent
			Room * destination;


};

#endif
