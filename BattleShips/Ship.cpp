#include "Ship.h"
#include"Main.h"
using namespace std;

void coutName(Type t)
{
	{
		switch (t) {
		case Destroyer:
			cout << "Destroyer";
			break;
		case Submarine:
			cout << "Submarine";
			break;
		case Cruiser:
			cout << "Cruiser";
			break;
		case Battleship:
			cout << "Battleship";
			break;
		case Carrier:
			cout << "Carrier";
			break;
		}
	}
}

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
		wait += w;
}

int Ship::getWait() const
{
	return wait;
}

bool Ship::setHp(int _hp)
{
	if(hp!=0)hp += _hp;
	if (hp == 0) {
		destroy();
		cout << "Sunk "; coutName(type);cout<< endl;
		return true;
	}
	else { cout << "Hit "; coutName(type); cout << endl; }
	return false;
}

