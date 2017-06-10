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
	effect = NONE;
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

void Player::reveal(int x, int y,Type t,Player&p,int i)
{
	if (t == Destroyer) {
		if(board.setVisible(x, y, board.check(x, y),effect))ships[i].setHp(-1);
		p.setEffect(SHIELD);
	}
	else if (t == Submarine) {
		if (board.setVisible(x, y, board.check(x, y), effect))ships[i].setHp(-1);
		setEffect(HIGH_MISS);
	}
	else if (t == Cruiser) {
		if (board.setVisible(x, y, board.check(x, y), effect))ships[i].setHp(-1);
		p.setEffect(HEAL);
	}
	else if (t == Battleship) {
		for (int i = (x - 1 < 1 ? 1 : x - 1); i <= (x + 1 < Xsize ? x + 1 : Xsize); i++)
			for (int j = (y - 1 < 1 ? 1 : y - 1); j <= (y + 1 < Ysize ? y + 1 : Ysize); j++)
				if (board.setVisible(i, j, board.check(i, j), effect))ships[i].setHp(-1);
	}
	else if (t == Carrier) {
		if (board.setVisible(x, y, board.check(x, y), effect))ships[i].setHp(-1);
		system("CLS");
		drawGame2(this,p);
		cout << "Shoot again:" << endl;
		cin >> x >> y;
		if (board.setVisible(x, y, board.check(x, y), effect))ships[i].setHp(-1);
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
				p.reveal(x, y, ships[i].getType(),*this,i);
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

void Player::setEffect(Effect e)
{
	effect = e;
}

Effect Player::getEffect() const
{
	return effect;
}

int Player::getShipCount() const
{
	return shipCount;
}



