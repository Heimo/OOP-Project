#include "Ship.h"
#include<iostream>
using namespace std;

Ship::Ship()
{
	destroyed = 0;
	size = 0;
	hp = 0;
}

Ship::Ship(Type _type)
{
	switch (_type) {
	case Destroyer:
		hp = 2;
		size = 2;
		type = _type;
		break;
	case Submarine:
		hp = 3;
		size = 3;
		type = _type;
		break;
	case Cruiser:
		hp = 3;
		size = 3;
		type = _type;
		break;
	case Battleship:
		hp = 4;
		size = 4;
		type = _type;
		break;
	case Carrier:
		hp = 5;
		size = 5;
		type = _type;
		break;
	}
	destroyed = 0;
	wait = 0;
}

Ship Ship::operator=(Ship & s)
{
	this->hp = s.hp;
	this->size = s.size;
	this->type = s.type;
	this->wait = s.wait;
	return *this;
}

void Ship::destroy()
{
	destroyed = true;
}

bool Ship::isDestroyed() const
{
	return destroyed;
}

int Ship::getSize() const
{
	return size;
}

void Ship::Cout()
{
	cout << hp << " " << size << " " << type << " " << destroyed << endl;
}

Type Ship::getType() const
{
	return type;
}

void Ship::setWait(int w)
{
	wait = w;
}

int Ship::getWait() const
{
	return wait;
}
