#ifndef __WORLD_H_
#define __WORLD_H_

#include <string>
#include <list>

using namespace std;

class Entity;
class Player;

class World 
{
	public:
			World();
			~World();

			bool Command(vector<string>&);
			void Gameloop();


};

#endif