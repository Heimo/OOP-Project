#pragma once
#define Xsize 9
#define Ysize 9
class Board {
private:
	int f[Xsize][Ysize];
	char fVisible[Xsize][Ysize];
public:
	Board();
	void display();
	void displayVisible();
	void generate();
	void reveal(int, int);
	void revealAdj(int, int);

};
