#pragma once
#include"Board.h"
#include"Ship.h"

class Player {
	Board board;
	Ship ships[5];
	int shipCount;
public:
	Player();
	void addShip(Type);
	void showBoard();
	void showEntireBoard();
	virtual void reveal(int,int,Type,Player&);
	int attack(Player&);
	void showLine(int);
};