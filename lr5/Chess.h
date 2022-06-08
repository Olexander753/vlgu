#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Result.h"

using namespace std;

class Chess
{
	vector<Player> ChessPlayer;

public:
	Chess() {};
	virtual ~Chess() {};

	void getChessPlayer();
	void addChessPlayer(Player& men);
};

void Chess::getChessPlayer()
{
	for (int i = 0; i < ChessPlayer.size(); i++)
	{
		ChessPlayer[i].getName();
		ChessPlayer[i].getResults();
		cout << endl;
	}
}

void Chess::addChessPlayer(Player& men)
{
	ChessPlayer.push_back(men);
}