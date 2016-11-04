#include <Entity.h>
#include <iostream>

using namespace std;


	Entity::Entity(char * n, char * d, Entity * p = NULL) 
	{
		name = n;
		desc = d;
		parent = p;

		if (parent != NULL)
			//entities.push_back(parent);
			// Adding myself to my parent entities
			parent->entities.push_back(this);
	}

	void Entity::Look()
	{
	
		cout << name << endl;
		cout << desc << endl;
	
	
	}

	Entity::~Entity() {}

	void Entity::Update() {}


