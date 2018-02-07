#include "BoardView.h"
//#include "Board.h"

int main()
{
	Board b;
	BoardView V(&b);
	V.StartGame();
	//V.TestGame();

	return 0;
}