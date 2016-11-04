#ifndef __ENTITY_H_
#define __ENTITY_H_

#include <string>
#include <list>

using namespace std;

class Entity 
{


	public:
			//Methods
		Entity(char * n, char * d, Entity* p);
			virtual ~Entity();
			virtual void Look();
			virtual void Update();

			//Members
			std::string name;
			std::string desc;


			//Point to parent
			Entity* parent;
			// list of entities
			list<Entity*> entities;

};


#endif
