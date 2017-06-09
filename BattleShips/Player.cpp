#include "Player.h"
#include<iostream>
#include <ctime>
#include"Main.h"
using namespace std;

Player::Player()
{
	shipCount = -1;
	srand(time(NULL));
	addShip(Carrier);
	//board.display();
	addShip(Battleship);
	//board.display();
	addShip(Cruiser);
	//board.display();
	addShip(Submarine);
	//board.display();
	addShip(Destroyer);
}

void Player::addShip(Type t)
{
	shipCount++;
	ships[shipCount] = Ship(t);
	board.generate(ships[shipCount].getSize(), t);
	
}

void Player::showBoard()
{
	board.displayVisible();
}

void Player::showEntireBoard()
{
	board.display();
}

void Player::reveal(int x, int y,Type t,Player&p)
{
	if (t == Destroyer) {
		if (board.check(x, y))board.setVisible(x,y,'X');
		else board.setVisible(x, y, 'O');
	}
	else if (t == Submarine) {
		if (board.check(x, y))board.setVisible(x, y, 'X');
		else board.setVisible(x, y, 'O');
	}
	else if (t == Cruiser) {
		if (board.check(x, y))board.setVisible(x, y, 'X');
		else board.setVisible(x, y, 'O');
	}
	else if (t == Battleship) {
		for (int i = (x - 1 < 0 ? 0 : x - 1); i <= (x + 1 < Xsize ? x + 1 : Xsize); i++)
			for (int j = (y - 1 < 0 ? 0 : y - 1); j <= (y + 1 < Ysize ? y + 1 : Ysize); j++)
				if (board.check(i, j) != 0 && board.check(i, j) != 6)board.setVisible(x, y, 'X');
				else board.setVisible(x, y, 'O');
	}
	else if (t == Carrier) {
		if (board.check(x, y))board.setVisible(x, y, 'X');
		else board.setVisible(x, y, 'O');
		system("CLS");
		drawGame2(this,p);
		cout << "Shoot again:" << endl;
		cin >> x >> y;
		if (board.check(x, y))board.setVisible(x, y, 'X');
		else board.setVisible(x, y, 'O');
	}
	
}

int Player::attack(Player &p)
{
	cout << "Select what ship to attack with:" << endl;
	int num = 0;
	for (int i = 0; i < 5; i++) {
		if (!ships[i].isDestroyed()) {
			num++;
			//ships[i].Cout();
			switch (ships[i].getType()) {
			case Destroyer:
				cout << num << " - Destroyer";
				break;
			case Submarine:
				cout << num << " - Submarine";
				break;
			case Cruiser:
				cout << num << " - Cruiser";
				break;
			case Battleship:
				cout << num << " - Battleship";
				break;
			case Carrier:
				cout << num << " - Carrier";
				break;
			}
			if (ships[i].getWait() != 0)cout << "(" << ships[i].getWait() << ")" << endl;
			else cout << endl;
		}
	}
	int select = 0;
	cin >> select;
	while (select<1 || select>shipCount+1) {
		cout << "Select Valid option:" << endl;
		cin >> select;
	}
	int x, y;
	cout << "Select coordinates:" << endl;
	cin >> x >> y;
	cout << "shooting " << x << "," << y << endl;
	int i2 = 0;
	num = 0;
	for (int i = 0; i < 5; i++) {
		if (!ships[i].isDestroyed()) {
			num++;
			if (num == select) {
				p.reveal(x, y, ships[i].getType(),*this);
				i2 = i;
			}
		}
	}
	ships[i2].setWait(num-1);
	return 0;
}

void Player::showLine(int l)
{
	board.displayLine(l);
}



