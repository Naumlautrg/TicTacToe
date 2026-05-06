#pragma once
#include <array>

#include "TicTacToeEnums.h"
#include "TicTacToeConstants.h"

class TicTacToeGame
{
private:
	bool gameWon = false;
	
	std::array<char, 9> currentBoard;
	std::array<char, 9> startBoard = {'1','2','3','4','5','6','7','8','9'};

	void printCurrentBoard() const;
	void printStartBoard();
	void updateBoard(int moveIndex, const PlayerType type);

	void playGameSimple();
	void playGameHard();
	char playAgain();

public:
	TicTacToeGame();

	void startGame();

};
