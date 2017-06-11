#include "AI.h"

AI::AI()
{
	Player();
	playerNum = 1;
}

void AI::reveal(int x, int y, Type t, Player&p, int i2)
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
		cout << "Shoot again:" << endl;
		cin >> x >> y;
		while ((x<1 || x>Ysize) || (y<1 || y>Xsize) || getBoard().checkChar(x, y) == 'X') {
			cout << "Invalid coordinates. Select again:" << endl;
			cin >> x >> y;
		}
		if (board.setVisible(x, y, board.check(x, y), effect, p.getEffect()))shipSetHp(x, y, p);
	}

}

int AI::attack(Player &p)
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
	//
	select = rand() % (shipCount + 1) + 1;
	cout << select << endl;
	while (check) {
		if (select >= 1 && select <= shipCount + 1) {
			for (int i = 0; i < 5; i++) {
				if (!ships[i].isDestroyed()) {
					num++;
					if (select == num) {
						num = 0;
						if (ships[i].getWait() != 0) {
							//cout << "Ship is on Cooldown. Select another one:" << endl;
							//
							select = rand() % (shipCount + 1) + 1;
							cout << select << endl;
							break;
						}
						else {
							check = false;
							break;
						}
					}
				}

			}
		}
		else {
			//cout << "Select Valid option:" << endl;
			//
			select = rand() % (shipCount+1) + 1;
		}
	}
	int x, y;
	//cout << "Select coordinates:" << endl;
	//
	x = rand() / Ysize + 1;
	y = rand() / Xsize + 1;
	while ((x<1 || x>Ysize) || (y<1 || y>Xsize) || p.getBoard().checkChar(x, y) == 'X') {
		//cout << "Invalid coordinates. Select again:" << endl;
		//
		x = rand() / Ysize + 1;
		y = rand() / Xsize + 1;
	}
	int i2 = 0;
	num = 0;
	for (int i = 0; i < 5; i++) {
		if (!ships[i].isDestroyed()) {
			num++;
			if (num == select) {
				p.reveal(x, y, ships[i].getType(), *this, i);
				i2 = i;
			}
		}
	}
	ships[i2].setWait(shipCount + 1);
	return 0;
}