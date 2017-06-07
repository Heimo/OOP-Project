#include <iostream>
#include "Board.h"
#include "Ship.h"
#include"Player.h"
using namespace std;

int main()
{
	Player p;
	p.showEntireBoard();
	p.showBoard();	
	int x, y,nship;
	while (true) {
		cout << "Choose Ship:\n1 - Carrier\n2 - Battleship\n3 - Cruiser\n4 - Submarine\n5 - Destroyer\n";
		cin >> nship;
		cout << "Select coordinates:" << endl;
		cin >> x >> y;
		cout << "shooting " << x << "," << y << endl;
		p.reveal(x, y);
		p.showBoard();
	}

	system("pause");
	return 0;
}