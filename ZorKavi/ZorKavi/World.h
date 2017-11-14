#ifndef __WORLD_H_
#define __WORLD_H_

#include <string>
#include <list>
#include <vector>

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

			void Help();

			list<Entity*> entities;
			Player* player;


};

#endif