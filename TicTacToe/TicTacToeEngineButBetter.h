#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>

#include "Random.h"
#include "TicTacToeConstants.h"

class TicTacToeEngineButBetter
{
private:
	const int winCon[8][3] = {
	{0,1,2}, {3,4,5}, {6,7,8},
	{0,3,6}, {1,4,7}, {2,5,8},
	{0,4,8}, {2,4,6}
	};

	std::vector<char> board = std::vector<char>(9, TicTacToeConstants::MOVE_EMPTY);

	Random randomizer;

	// move deciding/reading functions
	int minimax(bool isMaximizing, int h);

public:
	TicTacToeEngineButBetter() = default;

	int decideFirstPlay();
	char checkWin();
	bool isFull();
	std::vector<int> getLegalMoves();

	int getBestMove();
	int readPlayerMove();
};

