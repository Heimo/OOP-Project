#include <iostream>
#include "Board.h"
#include "Ship.h"
#include"AI.h"
using namespace std;

enum GameState {STARTUP,PLAYER_TURN,AI_TURN,PLAYER_WIN,AI_WIN};

void drawGame(Player& p, Player& p2) {
	cout << "Your Board:            AI Board:" << endl;
	for (int i = 0; i < Ysize; i++) {
		p.showLine(i);
		cout << "     ";
		p2.showLine(i);
		cout << endl;
	}
}
void drawGame2(Player*p, Player&p2) {
	cout << "Your Board:            AI Board:" << endl;
	for (int i = 0; i < Ysize; i++) {
		p2.showLine(i);
		cout << "     ";
		p->showLine(i);
		cout << endl;
	}
}


int main()
{
	GameState state = STARTUP;
	Player p;
	AI ai;
	//Player aia = &ai;
	state = PLAYER_TURN;
	srand(time(NULL));
	while (true) {
		if (state == PLAYER_TURN) {
			p.updateWait();
			system("CLS");
			drawGame(p, ai);
			p.attack(ai);
			if (ai.getShipCount()+1 == 0)state = PLAYER_WIN;
			else {
				system("CLS");
				drawGame(p, ai);
				cout << endl << "AI's turn to attack" << endl;
				system("pause");
				state = AI_TURN;
			}
			ai.healEffect();
			ai.setEffect(NONE);
		}else if (state == AI_TURN) {
			ai.updateWait();
			system("CLS");
			drawGame(p, ai);
			ai.attack(p);
			
			if (p.getShipCount()+1 == 0)state = AI_WIN;
			else {
				system("CLS");
				drawGame(p, ai);
				cout << endl << "Player's turn to attack" << endl;
				system("pause");
				state = PLAYER_TURN;
			}
			p.healEffect();
			p.setEffect(NONE);
		}

		if (state == AI_WIN) {
			system("CLS");
			drawGame(p, ai);
			cout << "You lost. The computer won." << endl;
			break;
		}
		if (state == PLAYER_WIN) {
			system("CLS");
			drawGame(p, ai);
			cout << "You won. The computer lost." << endl;
			break;
		}

		
	}

	system("pause");
	return 0;
}