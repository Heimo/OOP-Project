#include "Player.h"
#include <ctime>

Player::Player()
{
	srand(time(NULL));
	addShip(Carrier);
	board.display();
	addShip(Battleship);
	board.display();
	addShip(Cruiser);
	board.display();
	addShip(Submarine);
	board.display();
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

