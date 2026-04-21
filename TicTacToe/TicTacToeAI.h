#pragma once
#include "Random.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <unordered_map>

class TicTacToeEngine : public Random
{
private:
	friend class TicTacToeGame;

	std::unordered_map<std::string, std::vector<int>> AIMoveIndexes;

	std::unordered_map<std::string, std::vector<int>> playerMoveIndexes;

	
	// Takes board index (i.e. move number - 1) not spotChoices index
	void loadAIMove(int moveIndex);
	// Takes board index (i.e. move number - 1) not spotChoices index
	void loadPlayerMove(int moveIndex);

	std::vector<int> spotChoices{ 1,2,3,4,5,6,7,8,9 };
public:

	
	TicTacToeEngine();

	// input "P" for player or "A" for AI depending on which win con to check
	bool checkWinCon(const char playerOrAI);
	
	int generateMove();
	

	int readPlayerMove();

};
