#include "TicTacToeEngine.h"

bool TicTacToeEngine::checkWinCon(PlayerType type)
{
	if (type == PlayerType::AI)
	{
		for (const auto& winCondition : winConditions)
		{
			if (board[winCondition[0]] == TicTacToeConstants::MOVE_AI
				&& board[winCondition[1]] == TicTacToeConstants::MOVE_AI
				&& board[winCondition[2]] == TicTacToeConstants::MOVE_AI)
				return true;
		}
	}

	else if (type == PlayerType::Player)
	{
		for (const auto& winCondition : winConditions)
		{
			if (board[winCondition[0]] == TicTacToeConstants::MOVE_HUMAN
				&& board[winCondition[1]] == TicTacToeConstants::MOVE_HUMAN
				&& board[winCondition[2]] == TicTacToeConstants::MOVE_HUMAN)
				return true;
		}
	}

	return false;
}

bool TicTacToeEngine::movesAvailable()
{
	for (char c : board)
	{
		if (c == TicTacToeConstants::MOVE_EMPTY)
			return true;
	}
	return false;
}

std::array<char, 9> TicTacToeEngine::getBoard() const
{
	return board;
}

int TicTacToeEngine::generateMove()
{
	int move = randomizer.generateNum(0, BOARD_SPACES_NUM - 1);

	std::cout << "Hmmmmm.....";
	std::this_thread::sleep_for(std::chrono::milliseconds(1200));

	//record move
	while (true)
	{
		move = randomizer.generateNum(0, BOARD_SPACES_NUM - 1);

		if (board[move] == TicTacToeConstants::MOVE_EMPTY)
		{
			board[move] = TicTacToeConstants::MOVE_AI;
			return move;
		}
	}
}

int TicTacToeEngine::readPlayerMove()
{
	for (int i = 0; i < 100; ++i)
	{
		int move = 0;

		std::cout << "What is your move? ";
		std::cin >> move;

		int moveIndex = move - 1;

		if (moveIndex >= 0 && moveIndex < BOARD_SPACES_NUM && board[moveIndex] == ' ')
		{
			board[moveIndex] = TicTacToeConstants::MOVE_HUMAN;
			return moveIndex;
		}

		std::cout << "Invalid spot, please pick a spot on the board that has not been chosen\n\n";
	}

	std::cout << "You are really somethin ay?";
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::exit(1);
}