#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <unordered_map>

#include "TicTacToeEnums.h"
#include "TicTacToeConstants.h"
#include "Random.h"

class TicTacToeEngine
{
private:
	const int BOARD_SPACES_NUM = 9;

	/*	O is a player move,
	 *	X is an AI move, 
	 *	' ' is an empty space 
	*/
	std::array<char, 9> board =
	{ ' ', ' ', ' ',
	  ' ', ' ', ' ',
	  ' ', ' ', ' '};
	const std::vector<std::array<int, 3>> winConditions =
	{
		{ 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 },  // Column Wins
		{ 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 }, // Row Wins
		{ 0, 4, 8 }, { 2, 4, 6 }, // Diagonal Wins
	};

public:
	Random randomizer;

	TicTacToeEngine() = default;

	bool checkWinCon(PlayerType type);
	bool movesAvailable();

	std::array<char, 9> getBoard() const;
	int generateMove();
	int readPlayerMove();

};
