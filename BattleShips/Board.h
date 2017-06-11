#pragma once
#include"Ship.h"
#define Xsize 9
#define Ysize 9
enum Direction {LEFT=1,UP,RIGHT,DOWN};
enum Effect { NONE, HEAL, HIGH_MISS, SHIELD };
class Board {
private:
	int f[Xsize][Ysize];
	char fVisible[Xsize][Ysize];
public:
	Board();
	void display();
	void displayVisible();
	void generate(int,Type);
	int check(int, int);
	void revealAdj(int, int);
	void displayLine(int);
	bool setVisible(int, int, int,Effect,Effect);
	int getShipOnPos(int x, int y);
	char checkChar(int,int)const;
	void reverse(int,int);
};
