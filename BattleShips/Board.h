#pragma once
#include"Ship.h"
#define Xsize 9
#define Ysize 9
enum Direction {LEFT=1,UP,RIGHT,DOWN};
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
	void setVisible(int,int,char);

};
