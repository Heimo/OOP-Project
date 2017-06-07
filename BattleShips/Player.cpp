#include "Player.h"

Player::Player()
{
	board.generate(5);
	addShip(Destroyer);
	addShip(Submarine);
	addShip(Cruiser);
	addShip(Battleship);
	addShip(Carrier);
}

void Player::addShip(Type t)
{
	shipCount++;
	ships[shipCount] = Ship(t);
	
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

