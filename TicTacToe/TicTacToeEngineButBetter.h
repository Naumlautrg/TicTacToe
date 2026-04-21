#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class TicTacToeEngineButBetter
{
private:
	friend class TicTacToeGame;
	
	const char HUMAN = 'O';
	const char AI = 'X';
	const char EMPTY = '.';

	std::vector<char> board = std::vector<char>(9, EMPTY);
	
	int decideFirstPlay();
	char checkWin();
	bool isFull();
	std::vector<int> getLegalMoves();

	// move deciding/reading functions
	int minimax(bool isMaximizing, int h);
	int getBestMove();
	int readPlayerMove();

public:
	TicTacToeEngineButBetter() = default;
};

