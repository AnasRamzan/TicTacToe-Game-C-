#include <iostream>
#include <string>
#include "Tic_tac_toe.h"

using namespace std;

Tic_tac_toe::Tic_tac_toe()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = 0;
		}
	}
	row = 0;
	col = 0;
	token = 0;
	tie = false;
	player1 = "";
	player2 = "";
}

Tic_tac_toe::Tic_tac_toe(const Tic_tac_toe& obj)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = obj.board[i][j];
		}
	}
}

void Tic_tac_toe::setboardvalue(int value, int row, int col)
{
	board[row][col] = value;
}

void Tic_tac_toe::settoken(int t)
{
	token = t;
}

void Tic_tac_toe::settie(bool f)
{
	tie = f;
}

void Tic_tac_toe::setplayer1(string n1)
{
	player1 = n1;
}

void Tic_tac_toe::setplayer2(string n2)
{
	player2 = n2;
}

int Tic_tac_toe::getboardvalue(int row, int col)
{
	return board[row][col];
}

int Tic_tac_toe::gettoken()
{
	return token;
}

bool Tic_tac_toe::gettie()
{
	return tie;
}

void Tic_tac_toe::showboard()
{
	cout << "   |   |   \n";
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
	cout << "___|___|___\n";
	cout << "   |   |   \n";
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
	cout << "___|___|___\n";
	cout << "   |   |   \n";
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
	cout << "   |   |   \n";
}

void Tic_tac_toe::playerTurn()
{
	if (token == 1)
	{
		cout << player1 << "(1) :\n";
	}
	else
	{
		cout << player2 << "(2) :\n";
	}
	cout << "Enter box number you want to check (1-9)\n";
	int box;
	cin >> box;
	switch (box)
	{
	case 1:
		row = 0;
		col = 0;
		break;
	case 2:
		row = 0;
		col = 1;
		break;
	case 3:
		row = 0;
		col = 2;
		break;
	case 4:
		row = 1;
		col = 0;
		break;
	case 5:
		row = 1;
		col = 1;
		break;
	case 6:
		row = 1;
		col = 2;
		break;
	case 7:
		row = 2;
		col = 0;
		break;
	case 8:
		row = 2;
		col = 1;
		break;
	case 9:
		row = 2;
		col = 2;
		break;
	default:
		cout << "Enter valid box number!\n";
		playerTurn();
		return;
	}
	if (token == 1 && board[row][col] != 1 && board[row][col] != 2)
	{
		board[row][col] = token;
		token = 2;
	}
	else if (token == 2 && board[row][col] != 1 && board[row][col] != 2)
	{
		board[row][col] = token;
		token = 1;
	}
	else
	{
		cout << "This box is already filled!\n";
		playerTurn();
	}
}

bool Tic_tac_toe::checkWinner()
{
	for (int i = 0; i < 3; i++ )
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2]|| board[0][i] == board[1][i] && board[0][i] == board[2][i])
		{
			if (board[i][0] != 0 && board[i][1] != 0 && board[i][2] != 0 || board[0][i] != 0 && board[1][i] != 0 && board[2][i] != 0)
			{
				return true;
			}
		}
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
	{
		if (board[0][0] != 0 && board[1][1] != 0 && board[2][2] != 0 || board[0][2] != 0 && board[1][1] != 0 && board[0][2] != 0)
		{
			return true;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 0)
			{
				return false;
			}
		}
	}
		//-----
	tie = true;
	return true;
	
}