#pragma once
#include<iostream>
enum Type {Destroyer, Submarine, Cruiser, Battleship, Carrier };

class Ship {
private:
	int hp;
	int size;
	Type type;
	bool destroyed;
public:
	Ship();
	Ship(Type);
	Ship operator=(Ship& s);
	void destroy();
	bool isDestroyed()const;
};