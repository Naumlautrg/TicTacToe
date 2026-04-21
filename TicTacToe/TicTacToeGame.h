#pragma once
#include <array>

// removed so as to not give main access to these classes
//#include "TicTacToeAI.h"
//#include "TicTacToeEngineButBetter.h"

class TicTacToeGame
{
private:

	char play = 'Y';
	bool gameWon = false;
	

	std::array<char, 9> currentBoard;
	std::array<char, 9> startBoard = {'1','2','3','4','5','6','7','8','9'};


	void printStartBoard();
	void updateBoard(int moveIndex, const char playerOrAI);

	
	void playGameSimple();
	void playGameHard();
	char playAgain();

public:

	void startGame();

};
