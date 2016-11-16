#include "Exit.h"

Exit::Exit(char * name, char * description, Room * origin, Room * destination) :
	Entity(name, description, (Entity*) origin),
	closed(false),locked(false),key(NULL),destination(destination)
{
	type = EXIT;

	destination->entities.push_back(this);


}

//TODO ESCRIBIR MENSAJE DE CAMBIAR DE HABITACION

Exit::~Exit()
{

}

void Exit::Look() const
{
	cout << name << endl;
	cout << description << endl;
}
