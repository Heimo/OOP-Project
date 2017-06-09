#include <iostream>
#include "Board.h"
#include "Ship.h"
#include"Player.h"
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
			system("CLS");
			drawGame(p, ai);
			p.attack(ai);
			system("CLS");
			drawGame(p, ai);
			cout <<endl<< "AI's turn to attack" << endl;
			system("pause");
			state = AI_TURN;
		}

		if (state == AI_TURN) {
			system("CLS");
			drawGame(p, ai);
			//p.reveal(rand()%8+1, rand() % 8 + 1);
			system("CLS");
			drawGame(p, ai);
			cout <<endl<< "Player's turn to attack" << endl;
			system("pause");
			state = PLAYER_TURN;

		}
	}

	system("pause");
	return 0;
}