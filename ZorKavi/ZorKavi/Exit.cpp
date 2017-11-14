#include "Exit.h"

Exit::Exit(char * name, char * description, Room * origin, Room * destination, Direction direction, bool locked) :
	Entity(name, description, (Entity*) origin),
	closed(false),locked(locked),destination(destination),direction(direction)
{
	type = EXIT;

	destination->entities.push_back(this);


}

//TODO ESCRIBIR MENSAJE DE CAMBIAR DE HABITACION

Exit::~Exit()
{

}

string Exit::GetDirection() const
{
	string dir;

	switch (direction)
	{
	case N: dir = "NORTH";
		break;
	case S: dir = "SOUTH";
		break;
	case E: dir = "EAST";
		break;
	case W: dir = "WEST";
		break;
	default:
		dir = "???";
		break;
	}

	return dir;
}

void Exit::ChangeDirection()
{
	switch (direction)
	{
	case N: direction = S;
		break;
	case S:direction = N;
		break;
	case E:direction = W;
		break;
	case W: direction = E;
		break;
	default:
		break;
	}

	Room* temp = (Room*)parent;
	parent = destination;
	destination = temp;
}

void Exit::Look() const
{
	
	cout << "NAME: " << name << endl;
	cout << "LOCKED: " << (locked? "YES": "NO") << endl;
	cout << "DIRECTION: " << GetDirection() << endl;
	cout << "DESCRIPTION: " << description << endl << endl;

}

void Exit::Unlock()
{
	if (locked == false)
		return;

	if (locked == true)
	{
		locked = false;
		cout << "UNLOCKED: " << name << endl;
	}

}


