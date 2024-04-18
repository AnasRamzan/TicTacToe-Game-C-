#pragma once
using namespace std;
class Tic_tac_toe {
	int board[3][3];
	int row, col, token;
	bool tie;
	string player1;
	string player2;
public:
	Tic_tac_toe();
	Tic_tac_toe(const Tic_tac_toe &);
	void setboardvalue(int, int, int);
	void settoken(int);
	void settie(bool);
	void setplayer1(string);
	void setplayer2(string);
	int getboardvalue(int, int);
	int gettoken();
	bool gettie();
	void showboard();
	void playerTurn();
	bool checkWinner();
};
