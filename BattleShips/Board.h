#pragma once

class Board {
private:
	int f[9][9];
	char fVisible[9][9];
public:
	Board();
	void display();
	void displayVisible();
	void generate();
};
