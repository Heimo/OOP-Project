#include <iostream>
#include "Board.h"
#include "Ship.h"
using namespace std;

int main()
{
	Board b;
	b.generate();
	b.display();
	b.displayVisible();
	Ship s(Cruiser);
	int x, y,nship;
	while (true) {
		cout << "Choose Ship:\n1 - Carrier\n2 - Battleship\n3 - Cruiser\n4 - Submarine\n5 - Destroyer\n";
		cin >> nship;
		cout << "Select coordinates:" << endl;
		cin >> x >> y;
		cout << "shooting " << x << "," << y << endl;
		b.revealAdj(x, y);
		b.displayVisible();
	}

	system("pause");
	return 0;
}