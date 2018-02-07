#include "BoardView.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


BoardView::BoardView( Board* b)
{
	board = b;
}


BoardView::~BoardView()
{
}

void BoardView::show()
{
	cout << endl;

	cout << "    ";

	for (int k = 0; k < Board::FIELD_SIZE; k++)
	{
		cout << k + 1 << " ";
	}

	cout << endl << "    ";

	for (int m = 0; m < Board::FIELD_SIZE; m++)
	{
		cout << "_ ";
	}

	cout << endl;

	for (int i = 0; i < Board::FIELD_SIZE; i++)
	{
		cout << setw(2) << i + 1 << " " << "|";

		for (int j = 0; j < Board::FIELD_SIZE; j++)
		{
			//вывод клетки i,j (b->getCell())

			int Cell = board->getCell(i, j);
			if (Cell == X)
			{
				cout << "X" << "|";
			}
			else if (Cell == O)
			{
				cout << "O" << "|";
			}
			else if (Cell == NUL)
			{
				cout << "_" << "|";
			}
			else { }

			if (j == (Board::FIELD_SIZE - 1)) cout << endl;
		}
	}

	cout << endl;
}

void BoardView::StartGame()
{
	/*while (не конец)	// метод b->isWin()
	{
		спросить ход 1 - го игрока;
		b->MakeMove(...);
		show();

		if (не конец)
		{
		спросить ход 2 - го игрока;
		b->MakeMove(...);
		show();

		}
		}

		написать результат;
	}*/

	cout << "Game is on!";
	show();

	// the main cycle of game
	while (board->isWin() == NO_WIN)
	{
		bool testFail1 = false;
		do
		{
			int x, y;
			cout << "Player1 CROSS: input x,y" << endl;
			cin >> x;
			cin.ignore(255, '\n');

			cin >> y;
			cin.ignore(255, '\n');

			testFail1 = board->makeMove(x - 1, y - 1, X_PLAYER);
			show();
		} while (!testFail1);

		if (board->isWin() == NO_WIN)
		{
			bool testFail2 = false;
			do
			{
				int x, y;
				cout << "Player2 ZERO: input x,y" << endl;
				cin >> x;
				cin.ignore(255, '\n');

				cin >> y;
				cin.ignore(255, '\n');

				testFail2 = board->makeMove(x - 1, y - 1, O_PLAYER);
				show();
			} while (!testFail2);
		}
	} // end of while

	// shows result of game
	if (board->isWin() == X_WIN)
	{
		cout << "Player 1 CROSS win!!!" << endl;
	}
	else if (board->isWin() == O_WIN)
	{
		cout << "Player 2 ZERO win!!!" << endl;
	}
	else if (board->isWin() == DRAW)
	{
		cout << "Draw!!! Nobody wins :(" << endl;
	}
	else
	{

	}

	system("pause");

}

void BoardView::TestGame()
{
	cout << "Game is test!";
	show();

	srand(time(0));

	// the main cycle of game
	while (board->isWin() == NO_WIN)
	{
		bool testFail1 = false;
		do
		{
			int x, y;
			cout << "Player1 CROSS: input x,y" << endl;
			x = rand() % 10 + 1;
			cout << x << endl;

			y = rand() % 10 + 1;
			cout << y;

			testFail1 = board->makeMove(x - 1, y - 1, X_PLAYER);
			show();
		} while (!testFail1);

		
		if (board->isWin() == NO_WIN)
		{
			bool testFail2 = false;
			do
			{
				int x, y;
				cout << "Player2 ZERO: input x,y" << endl;
				x = rand() % 10 + 1;
				cout << x << endl;

				y = rand() % 10 + 1;
				cout << y;

				testFail2 = board->makeMove(x - 1, y - 1, O_PLAYER);
				show();
			} while (!testFail2);
		}
	}  // end of while

	// shows result of game
	if (board->isWin() == X_WIN)
	{
		cout << "Player 1 CROSS win!!!" << endl;
	}
	else if (board->isWin() == O_WIN)
	{
		cout << "Player 2 ZERO win!!!" << endl;
	}
	else if (board->isWin() == DRAW)
	{
		cout << "Draw!!! Nobody wins :(" << endl;
	}
	else
	{

	}

	system("pause");
}