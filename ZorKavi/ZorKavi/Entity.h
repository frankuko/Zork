#ifndef __ENTITY_H_
#define __ENTITY_H_

#include <string>
#include <list>

using namespace std;


enum EntityType
{
	ROOM,
	CREATURE,
	PLAYER,
	ENTITY,
	EXIT,
	ITEM
};

class Entity 
{


	public:
			//Methods
			Entity(char * , char * , Entity* );
			virtual ~Entity();
			virtual void Look();
			virtual void Update();

			//Members
			string name;
			string description;
			EntityType type;


			//Point to parent
			Entity* parent;


			// list of entities
			list<Entity*> entities;
			bool Find(Entity *) const;
			Entity * Find(EntityType ) const;
			void FindAll(EntityType, list<Entity*> &) const;

			

};


#endif
