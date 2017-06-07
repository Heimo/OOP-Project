#include "Board.h"
#include <iostream>
#include <ctime>
#include"Ship.h"
using namespace std;


Board::Board()
{
	for (int i = 0; i < 9; i++)
	{
		f[i][0] = i;
		f[0][i] = i;
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

void Board::generate(int size)
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
	srand(time(NULL));
	int random, random2, count;
	while (true) {
		count = size;
		random = rand() % (8 * 8) + 1;
		random2 = rand() % 2 + 1;
		//int* tempship[5];
		if (f[random / 8][random % 8] == 0) {
			count--;
			for (int i = 1; i < size; i++) {
				if (count <= 0)break;
				//1-left 3-right 2-up 4-down
				if (random2 == 1) {
					if (f[random / 8][random % 8 - i > 1 ? random % 8 - i : 1] == 0) {
						cout << "left" << endl;
						count--;
						random2 = 3;
					}
				}
				if (random2 == 3) {
					cout << "right" << endl;
					if (f[random / 8][random % 8 + i < Xsize ? random % 8 + i : Xsize] == 0) {
						count--;
						random2 = 1;
					}
				}
				if (random2 == 2) {
					if (f[random / 8 - i > 1 ? random / 8 - i : 1][random % 8] == 0) {
						cout << "up" << endl;
						count--;
						random2 = 4;
					}
				}
				if (random2 == 4) {
					//cout << random % 8 << " " << (random / 8 + i < Xsize ? random / 8 + i : Xsize) << " " << f[random / 8 + i < Xsize ? random / 8 + i : Xsize][random % 8] << endl;
					if (f[random / 8 + i < Xsize ? random / 8 + i : Xsize][random % 8] == 0) {
						cout << "down" << endl;
						count--;
						random2 = 2;
					}
				}
			}

			if (count <= 0) {
				count = size;
				if (f[random / 8][random % 8] == 0) {
					cout << random % 8 << " " << random / 8 << endl;
					count--;
					f[random / 8][random % 8] = 1;
					for (int i = 1; i <size; i++) {
						if (count <= 0)break;
						//1-left 3-right 2-up 4-down
						if (random2 == 1) {
							if (f[random / 8][random % 8 - i >= 1 ? random % 8 - i : 1] == 0) {
								f[random / 8][random % 8 - i >= 1 ? random % 8 - i : 1] = 1;
								count--;
							}
							random2 = 3;
						}
						if (random2 == 3) {
							if (f[random / 8][random % 8 + i < Xsize ? random % 8 + i : Xsize] == 0) {
								f[random / 8][random % 8 + i < Xsize ? random % 8 + i : Xsize] = 1;
								count--;
							}
							random2 = 1;
						}
						if (random2 == 2) {
							if (f[random / 8 - i > 1 ? random / 8 - i : 1][random % 8] == 0) {
								f[random / 8 - i > 1 ? random / 8 - i : 1][random % 8] = 1;
								count--;
							}
							random2 = 4;
						}
						if (random2 == 4) {
							if (f[random / 8 + i < Xsize ? random / 8 + i : Xsize][random % 8] == 0) {
								f[random / 8 + i < Xsize ? random / 8 + i : Xsize][random % 8] = 1;
								count--;
							}
							random2 = 2;
						}

					}
					
				}
			
				cout << "maybe" << endl;
				break;
			}
		}
	}
}

void Board::reveal(int x, int y)
{
	if (f[y][x])fVisible[y][x] = 'X';
	else fVisible[y][x] = 'O';
}

void Board::revealAdj(int x, int y)
{
	for (int i = (x - 1 < 0 ? 0 : x - 1); i <= (x + 1 < Xsize ? x + 1 : Xsize); i++)
		for (int j = (y - 1 < 0 ? 0 : y - 1); j <= (y + 1 < Ysize ? y + 1 : Ysize); j++)
			reveal(i, j);
}
