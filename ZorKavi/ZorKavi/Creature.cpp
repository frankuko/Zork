#include "Creature.h"



Creature::Creature(char * name, char * description, Room* room ):
	Entity(name, description,(Entity*)room)
{
	//TODO DEFINIR TIPO CREATURE

}


Creature::~Creature()
{
}


void Creature::Look(const vector<string> & args) const
{
}

void Creature::Update()
{
}