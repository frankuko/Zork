#include <Entity.h>
#include <iostream>

using namespace std;


	Entity::Entity( char * name,  char * description, Entity * parent = NULL) :
		name(name),description(description),parent(parent)
	{

		type = ENTITY;

		if (parent != NULL)
			//entities.push_back(parent);
			// Adding myself to my parent entities
			parent->entities.push_back(this);
	}

	void Entity::Look()
	{
	
		cout << "\t" << name << endl;
		cout << "\t\t" << description << endl;
	
	
	}

	Entity::~Entity() {}

	void Entity::Update() {}


	/*
		Find one ocurrence in the list
	*/
	bool Entity::Find(Entity * entity) const
	{
		//TODO CBEGIN Y CEND?
		for (list<Entity*>::const_iterator it = entities.begin(); it != entities.end(); ++it)
		{
			if (entity == (*it))
				return true;
		}

		return false;
	}

	Entity* Entity::Find(EntityType type) const
	{
		for (list<Entity*>::const_iterator it = entities.begin(); it != entities.end(); ++it)
		{
			if ((*it)->type == type)
				return (*it);
		}

		return NULL;

	}



	void Entity::FindAll(EntityType type, list<Entity*>& my_list) const
	{

		for (list<Entity*>::const_iterator it = entities.begin(); it != entities.end(); ++it)
		{
			if ((*it)->type == type)
				my_list.push_back(*it);
		}
	}


