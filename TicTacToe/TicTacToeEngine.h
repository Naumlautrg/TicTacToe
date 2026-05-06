#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <unordered_map>

#include "Enums.h"
#include "Random.h"

class TicTacToeEngine
{
private:
	std::unordered_map<std::string, std::vector<int>> AIMoveIndexes;
	std::unordered_map<std::string, std::vector<int>> playerMoveIndexes;

	std::vector<int> spotChoices { 1, 2, 3,
								   4, 5, 6,
								   7, 8, 9 };
	
	/* Constants */
	const int BOARD_SPACES_NUM = 9;

	// Takes board index (i.e. move number - 1) not spotChoices index
	void loadAIMove(int moveIndex);
	// Takes board index (i.e. move number - 1) not spotChoices index
	void loadPlayerMove(int moveIndex);

public:
	Random randomizer;

	TicTacToeEngine() = default;

	// input "P" for player or "A" for AI depending on which win con to check
	bool checkWinCon(const char playerOrAI);
	
	int generateMove();
	int readPlayerMove();

};
