#include <iostream>
#include "Board.h"
using namespace std;

int main()
{
	Board b;
	b.generate();
	b.display();
	b.displayVisible();

	system("pause");
	return 0;
}