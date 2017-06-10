#pragma once
#include"Board.h"
#include"Ship.h"

class Player {
	Board board;
	Ship ships[5];
	int shipCount;
	Effect effect;
public:
	Player();
	void addShip(Type);
	void showBoard();
	void showEntireBoard();
	virtual void reveal(int,int,Type,Player&,int);
	int attack(Player&);
	void showLine(int);
	void setEffect(Effect);
	Effect getEffect()const;
	int getShipCount()const;
};