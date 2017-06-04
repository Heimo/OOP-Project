#include "Board.h"
#include <iostream>
#include <ctime>
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

void Board::generate()
{
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
	}
}
