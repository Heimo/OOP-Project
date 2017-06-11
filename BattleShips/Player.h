#pragma once
#include"Board.h"
#include"Ship.h"

class Player {
protected:
	Ship ships[5];
	Board board;
	Effect effect;
	int shipCount;
	bool heal;
public:
	int playerNum;
	Player();
	void addShip(Type);
	void showBoard();
	void showEntireBoard();
	virtual void reveal(int, int, Type, Player&, int);
	virtual int attack(Player&);
	void showLine(int);
	void setEffect(Effect);
	Effect getEffect()const;
	int getShipCount()const;
	void shipSetHp(int, int, Player&);
	void updateWait(int b = 0);
	Board getBoard()const;
	void healEffect();
};