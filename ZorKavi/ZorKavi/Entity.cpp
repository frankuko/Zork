#include <Entity.h>
#include <iostream>

using namespace std;


	Entity::Entity(const char * name, const char * description, Entity * parent = NULL) :
		name(name),desc(description),parent(parent)
	{

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


