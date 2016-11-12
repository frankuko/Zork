#include <Entity.h>
#include <iostream>

using namespace std;


	Entity::Entity(const char * name, const char * description, Entity * parent = NULL) :
		name(name),description(description),parent(parent)
	{

		if (parent != NULL)
			//entities.push_back(parent);
			// Adding myself to my parent entities
			parent->entities.push_back(this);
	}

	void Entity::Look()
	{
	
		cout << name << endl;
		cout << description << endl;
	
	
	}

	Entity::~Entity() {}

	void Entity::Update() {}


