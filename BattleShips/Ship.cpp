#include "Ship.h"

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
}

void Ship::destroy()
{
	destroyed = true;
}

bool Ship::isDestroyed() const
{
	return destroyed;
}
