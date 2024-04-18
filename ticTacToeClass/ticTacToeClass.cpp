
#include <iostream>
#include <string>
#include "Tic_tac_toe.h"
using namespace std;

int main()
{
	string name1, name2;
	int turn;
	Tic_tac_toe t;
	cout << "Enter name of Player 1: ";
	getline(cin, name1);
	t.setplayer1(name1);
	cout << "Enter name of Player 2: ";
	getline(cin, name2);
	t.setplayer2(name2);
	cout << "Which player will have first turn?(1 or 2) \n";
	cin >> turn;
	t.settoken(turn);
	do {
		system("cls");
		t.showboard();
		t.playerTurn();
		t.checkWinner();
	} while (!t.checkWinner());
	if (t.gettie() == false && t.gettoken() == 1)
	{
		system("cls");
		t.showboard();
		cout << name2 << " has won!\n";
	}
	else if (t.gettie() == false && t.gettoken()==2)
	{
		system("cls");
		t.showboard();
		cout << name1 << " has won!\n";
	}
	
	else
	{
		system("cls");
		t.showboard();
		cout << "Its a tie!\n";
	}
	/*t.showboard();
	t.playerTurn();
	t.showboard();
	t.checkWinner();*/
}

