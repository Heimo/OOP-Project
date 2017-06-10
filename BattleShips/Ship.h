#pragma once
#include<iostream>
enum Type {Destroyer=1, Submarine, Cruiser, Battleship, Carrier };

class Ship {
private:
	int hp;
	int size;
	Type type;
	bool destroyed;
	int wait;
public:
	Ship();
	Ship(Type);
	Ship operator=(Ship& s);
	void destroy();
	bool isDestroyed()const;
	int getSize()const;
	void Cout();
	Type getType()const;
	void setWait(int w);
	int getWait()const;
	void setHp(int);
};