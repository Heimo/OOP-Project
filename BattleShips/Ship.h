#pragma once

enum Type { Destroyer, Submarine, Cruiser, Battleship, Carrier };

class Ship {
private:
	int hp;
	int size;
	Type type;
	bool destroyed;
public:
	Ship(Type);
	void destroy();
	bool isDestroyed()const;
};