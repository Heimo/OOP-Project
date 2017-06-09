#include "Player.h"
#include<iostream>
#include <ctime>
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

void Player::reveal(int x, int y)
{
	board.reveal(x, y);
}

int Player::showAvailableShips()
{
	cout << "Select what ship to attack with:" << endl;
	int num = 0;
	for (int i = 0; i <= shipCount; i++) {
		if (!ships[i].isDestroyed()) {
			num++;
			//ships[i].Cout();
			switch (ships[i].getType()) {
			case Destroyer:
				cout << num << " - Destroyer" << endl;
				break;
			case Submarine:
				cout << num << " - Submarine" << endl;
				break;
			case Cruiser:
				cout << num << " - Cruiser" << endl;
				break;
			case Battleship:
				cout << num << " - Battleship" << endl;
				break;
			case Carrier:
				cout << num << " - Carrier" << endl;
				break;
			}
		}
	}
	return 0;
}

void Player::showLine(int l)
{
	board.displayLine(l);
}



