#pragma once
#include"Player.h"
#include<ctime>
using namespace std;
class AI : public Player {
public:
	AI();
	virtual void reveal(int, int, Type, Player&, int);
	virtual int attack(Player&);
	//void reveal(Player);
};