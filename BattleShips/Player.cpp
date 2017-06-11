#include "Player.h"
//#include<iostream>
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
	playerNum = 0;
	heal = false;
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

void Player::reveal(int x, int y,Type t,Player&p,int i2)
{
	if (t == Destroyer) {
		if (board.setVisible(x, y, board.check(x, y), effect,p.getEffect()))shipSetHp(x, y, p);
		p.setEffect(SHIELD);

	}
	else if (t == Submarine) {
		if (board.setVisible(x, y, board.check(x, y), effect, p.getEffect()))shipSetHp(x, y, p);
		setEffect(HIGH_MISS);
	}
	else if (t == Cruiser) {
		if (board.setVisible(x, y, board.check(x, y), effect, p.getEffect()))shipSetHp(x, y, p);
		p.setEffect(HEAL);
	}
	else if (t == Battleship) {
		for (int i = (x - 1 < 1 ? 1 : x - 1); i <= (x + 1 < Xsize ? x + 1 : Xsize); i++)
			for (int j = (y - 1 < 1 ? 1 : y - 1); j <= (y + 1 < Ysize ? y + 1 : Ysize); j++)
			{
				if (board.setVisible(i, j, board.check(i, j), effect, p.getEffect()))shipSetHp(i, j, p);
			}
	}
	else if (t == Carrier) {
		if (board.setVisible(x, y, board.check(x, y), effect, p.getEffect()))shipSetHp(x, y, p);
		//cout << "Shoot again:" << endl;
		//
		x = rand() / Ysize + 1;
		y = rand() / Xsize + 1;
		while ((x<1 || x>Ysize) || (y<1 || y>Xsize) || getBoard().checkChar(x, y) == 'X') {
			//cout << "Invalid coordinates. Select again:" << endl;
			//
			x = rand() / Ysize + 1;
			y = rand() / Xsize + 1;
		}
		if (board.setVisible(x, y, board.check(x, y), effect, p.getEffect()))shipSetHp(x, y, p);
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
	num = 0;
	bool check = true;
	cin >> select;
	while (check) {
		if (select >= 1 && select <= shipCount + 1) {
			for (int i = 0; i < 5; i++) {
				if (!ships[i].isDestroyed()) {
					num++;
					if (select == num) {
						num = 0;
						if (ships[i].getWait() != 0) {
							cout << "Ship is on Cooldown. Select another one:" << endl;
							cin >> select;
							break;
						}
						else {
							check = false;
							break;
						}
					}
				}
				
			}
		}else {
			cout << "Select Valid option:" << endl;
			cin >> select;
		}
	}
	int x, y;
	cout << "Select coordinates:" << endl;
	cin >> x >> y;
	while ((x<1 || x>Ysize) || (y<1 || y>Xsize) || p.getBoard().checkChar(x, y) == 'X') {
		cout << "Invalid coordinates. Select again:" << endl;
		cin >> x >> y;
	}
	num = 0;
	for (int i = 0; i < 5; i++) {
		if (!ships[i].isDestroyed()) {
			num++;
			if (num == select) {
				p.reveal(x, y, ships[i].getType(),*this,i);
				ships[i].setWait(shipCount + 1);
			}
		}
	}
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

void Player::shipSetHp(int x,int y,Player&p)
{
	int t = board.getShipOnPos(x, y);
	for (int i = 0; i < 5; i++) {
		if (t == ships[i].getType() && !ships[i].isDestroyed())
		{
			system("CLS");
			if (p.playerNum) {
				drawGame(*this, p);
			}
			else drawGame(p, *this);
			if (ships[i].setHp(-1)) {
				shipCount--;
				cout << "Ships left:" << shipCount+1 << endl;
				updateWait(1);
			}

			break;
		}
	}
	
	system("pause");
}

void Player::updateWait(int b)
{
	for (int i = 0; i < 5; i++) {
		if (!ships[i].isDestroyed()) {
			if(b!=0 && ships[i].getWait() != 0)ships[i].setWait(-1);
			else if (ships[i].getWait() != 0)ships[i].setWait(-1);
		}
	}
}

Board Player::getBoard() const
{
	return board;
}

void Player::healEffect()
{
	if (effect==HEAL) {
		for (int i = 0; i < 5; i++) {
			if (ships[i].getType() == Cruiser && !ships[i].isDestroyed()) {
				for (int j = 0; j < 9; j++)
				{
					for (int k = 0; k < 9; k++)
					{
						if (board.check(j, k) == 3 && board.checkChar(j, k) == 'X')board.reverse(j, k);
					}
				}
			}
		}
	}
}

