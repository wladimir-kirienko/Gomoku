#pragma once
#include "Board.h"

class BoardView
{
private:
	Board* board;
	void show();			// вывод поля
public:
	BoardView( Board* b);
	~BoardView();

	void StartGame();		// главный цикл, работает с пользователем
	void TestGame();		// главный цикл, работает с генератором случайных

};

