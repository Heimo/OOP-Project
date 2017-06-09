#include "Board.h"
#include <iostream>
#include <ctime>
using namespace std;


Board::Board()
{
	for (int i = 0; i < 9; i++)
	{
		f[i][0] = 6;
		f[0][i] = 6;
		fVisible[i][0] = 48 + i;
		fVisible[0][i] = 48 + i;
	}
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			f[i][j] = 0;
			fVisible[i][j] = '.';
		}
	}
}

void Board::display()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Board::displayVisible()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << fVisible[i][j] << " ";
		}
		cout << endl;
	}
}

void Board::generate(int size,Type t)
{/*
	//destroyer - 2
	srand(time(NULL));
	int random;
	while (true) {
		random = rand() % (8 * 8) + 1;
		cout << random << endl;
		if (f[random / 8][random % 8] == 0) {
			f[random / 8][random % 8] = 1;
			while (true) {
				int random2 = rand() % 4 + 1;
				switch (random2) {
				case 1:if (f[random / 8 - 1][random % 8] == 0) { f[random / 8 - 1][random % 8] = 1; break; }
				case 2:if (f[random / 8 + 1][random % 8] == 0) { f[random / 8 + 1][random % 8] = 1; break; }
				case 3:if (f[random / 8][random % 8 - 1] == 0) { f[random / 8][random % 8 - 1] = 1; break; }
				case 4:if (f[random / 8][random % 8 + 1] == 0) { f[random / 8][random % 8 + 1] = 1; break; }
				}
				break;
			}
			break;
		}
	}

	while (true) {
		random = rand() % (8 * 8) + 1;
		cout << random << endl;
		if (f[random / 8][random % 8] == 0) {
			f[random / 8][random % 8] = 1;
			while (true) {
				int random2 = rand() % 4 + 1;
				switch (random2) {
				case 1:if (f[random / 8 - 1][random % 8] == 0) { f[random / 8 - 1][random % 8] = 1; break; }
				case 2:if (f[random / 8 + 1][random % 8] == 0) { f[random / 8 + 1][random % 8] = 1; break; }
				case 3:if (f[random / 8][random % 8 - 1] == 0) { f[random / 8][random % 8 - 1] = 1; break; }
				case 4:if (f[random / 8][random % 8 + 1] == 0) { f[random / 8][random % 8 + 1] = 1; break; }
				}
				break;
			}
			break;
		}
	}*/
	int random, count; 
	Direction dir, initDir;
	while (true) {
		initDir = (Direction)(int)(rand() % 2 + 1);
		bool bUP = 1, bDOWN = 1, bLEFT = 1, bRIGHT = 1;
		count = size;
		random = rand() % (8 * 8) + 1;
		dir = initDir;
		if (f[random / 8][random % 8] == 0) {
			f[random / 8][random % 8] = 9;
			//cout <<"Trying with: " <<random % 8 << " " << random /8 <<" dir:"<<initDir<< endl;
			count--;
			for (int i = 1; i < size; i++) {
				/*if (dir == UP || dir == DOWN) {
					cout << random % 8 << " " << (random / 8 - i > 1 ? random / 8 - i : 1) << " " << f[random / 8 - i > 1 ? random / 8 - i : 1][random % 8] << endl;
					cout << random % 8 << " " << (random / 8 + i < Xsize ? random / 8 + i : Xsize) << " " << f[random / 8 + i < Xsize ? random / 8 + i : Xsize][random % 8] << endl;
				}
				if (dir == LEFT || dir == RIGHT) {
					cout << (random % 8 - i > 1 ? random % 8 - i : 1) << " " << random / 8 << " " << f[random / 8][random % 8 - i > 1 ? random % 8 - i : 1] << endl;
					cout << (random % 8 + i < Xsize ? random % 8 + i : Xsize) << " " << random / 8 << " " << f[random / 8][random % 8 + i < Xsize ? random % 8 + i : Xsize] << endl;
				}*/

				if (count <= 0)break;
				//1-left 3-right 2-up 4-down
				if (dir == LEFT) {
					if (bLEFT) {
						if (random % 8 - i > 0) {
							if (f[random / 8][random % 8 - i] == 0) {
								f[random / 8][random % 8 - i] = 9;
								//cout << "left" << endl;
								count--;
								dir = RIGHT;
							}
							else bLEFT = false;
						}
						else bLEFT = false;
						dir = RIGHT;
					}
					else dir = RIGHT;
				}

				if (count <= 0)break;

				if (dir == RIGHT) {
					if (bRIGHT) {
						if (random % 8 + i < Ysize) {
							if (f[random / 8][random % 8 + i] == 0) {
								f[random / 8][random % 8 + i] = 9;
								//cout << "right" << endl;
								count--;
								dir = LEFT;
							}
							else bRIGHT = false;
						}
						else bRIGHT = false;
						dir = LEFT;
					}
					else dir = LEFT;
				}

				if (count <= 0)break;

				if (dir == UP && bUP) {
					if (bUP) {
						if (random / 8 - i > 0) {
							if (f[random / 8 - i][random % 8] == 0) {
								f[random / 8 - i][random % 8] = 9;
								//cout << "up" << endl;
								count--;
								dir = DOWN;
							}
							else bUP = false;
						}
						else bUP = false;
						dir = DOWN;
					}
					else dir = DOWN;
				}

				if (count <= 0)break;

				if (dir == DOWN && bDOWN) {
					if (bDOWN) {
						if (random / 8 + i < Xsize) {
							if (f[random / 8 + i][random % 8] == 0) {
								f[random / 8 + i][random % 8] = 9;
								//cout << "down" << endl;
								count--;
								dir = UP;
							}
							else bDOWN = false;
						}
						else bDOWN = false;
						dir = UP;
					}
					else dir = UP;
				}
			}


			if (count <= 0) {
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (f[i][j] == 9)f[i][j] = t;
					}
				}

				//cout << "done with "<<t << endl;
				break;
			}
			else {
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (f[i][j] == 9)f[i][j] = 0;
					}
				}
				//cout << "NOPE" << endl;
			}
		}
	}
}


int Board::check(int x, int y)
{
	return f[y][x];
	
}

void Board::revealAdj(int x, int y)
{
	/*for (int i = (x - 1 < 0 ? 0 : x - 1); i <= (x + 1 < Xsize ? x + 1 : Xsize); i++)
		for (int j = (y - 1 < 0 ? 0 : y - 1); j <= (y + 1 < Ysize ? y + 1 : Ysize); j++)
			reveal(i, j);*/
}

void Board::displayLine(int l)
{
	for (int i = 0; i < Xsize; i++) {
		cout << fVisible[l][i] << " ";
	}
	}

void Board::setVisible(int x,int y,char c)
{
	fVisible[y][x] = c;
}

