#pragma once
#include"Board.h"
#include"Ship.h"

class Player {
	Board board;
	Ship ships[5];
	int shipCount = -1;
public:
	Player();
	void addShip(Type);
	void showBoard();
	void showEntireBoard();
	void reveal(int, int);
};