#include "TicTacToeEngine.h"

TicTacToeEngine::TicTacToeEngine()
{
	AIMoveIndexes = {
		{"col1", {}},
		{"col2", {}},
		{"col3", {}},
		{"row1", {}},
		{"row2", {}},
		{"row3", {}},
		{"diag1", {}},
		{"diag2", {}},
	};

	playerMoveIndexes = {
		{"col1", {}},
		{"col2", {}},
		{"col3", {}},
		{"row1", {}},
		{"row2", {}},
		{"row3", {}},
		{"diag1", {}},
		{"diag2", {}},
	};

}

void TicTacToeEngine::loadAIMove(int moveIndex)
{
	//check if move in main diag
	if (moveIndex % 4 == 0)
	{
		AIMoveIndexes["diag1"].push_back(moveIndex);
	}

	//check if move in secondary diag
	if ((moveIndex % 2 == 0) && !(moveIndex % 4 == 0))
	{
		AIMoveIndexes["diag2"].push_back(moveIndex);
	}

	if (moveIndex == 4)
	{
		AIMoveIndexes["diag2"].push_back(moveIndex);
	}



	//check if in first collum and which row
	if ((moveIndex % 3) == 0)
	{
		AIMoveIndexes["col1"].push_back(moveIndex);


		if (moveIndex < 6)
		{
			if (moveIndex < 3)
			{
				AIMoveIndexes["row1"].push_back(moveIndex);
				return;
			}

			AIMoveIndexes["row2"].push_back(moveIndex);
			return;
		}

		AIMoveIndexes["row3"].push_back(moveIndex);
		return;
	}
	
	//check if in second collum and which row
	if ((moveIndex % 3) == 1)
	{
		AIMoveIndexes["col2"].push_back(moveIndex);

		if (moveIndex < 6)
		{
			if (moveIndex < 3)
			{
				AIMoveIndexes["row1"].push_back(moveIndex);
				return;
			}

			AIMoveIndexes["row2"].push_back(moveIndex);
			return;
		}

		AIMoveIndexes["row3"].push_back(moveIndex);
		return;
	}

	//check if in thrid collum and which row 
	if ((moveIndex % 3) == 2)
	{
		AIMoveIndexes["col3"].push_back(moveIndex);

		if (moveIndex < 6)
		{
			if (moveIndex < 3)
			{
				AIMoveIndexes["row1"].push_back(moveIndex);
				return;
			}

			AIMoveIndexes["row2"].push_back(moveIndex);
			return;
		}

		AIMoveIndexes["row3"].push_back(moveIndex);
		return;
	}
}

void TicTacToeEngine::loadPlayerMove(int moveIndex)
{

	//check if in main diag
	if (moveIndex % 4 == 0)
	{
		playerMoveIndexes["diag1"].push_back(moveIndex);
	}

	//check if in secondary diag
	if ((moveIndex % 2 == 0) && !(moveIndex % 4 == 0))
	{
		playerMoveIndexes["diag2"].push_back(moveIndex);
	}

	if (moveIndex == 4)
	{
		playerMoveIndexes["diag2"].push_back(moveIndex);
	}



	//check if in first col and which row
	if ((moveIndex % 3) == 0)
	{
		playerMoveIndexes["col1"].push_back(moveIndex);


		if (moveIndex < 6)
		{
			if (moveIndex < 3)
			{
				playerMoveIndexes["row1"].push_back(moveIndex);
				return;
			}

			playerMoveIndexes["row2"].push_back(moveIndex);
			return;
		}

		playerMoveIndexes["row3"].push_back(moveIndex);
		return;
	}

	//check if in second col and which row
	if ((moveIndex % 3) == 1)
	{
		playerMoveIndexes["col2"].push_back(moveIndex);

		if (moveIndex < 6)
		{
			if (moveIndex < 3)
			{
				playerMoveIndexes["row1"].push_back(moveIndex);
				return;
			}

			playerMoveIndexes["row2"].push_back(moveIndex);
			return;
		}

		playerMoveIndexes["row3"].push_back(moveIndex);
		return;
	}

	//check if in third col and which row
	if ((moveIndex % 3) == 2)
	{
		playerMoveIndexes["col3"].push_back(moveIndex);

		if (moveIndex < 6)
		{
			if (moveIndex < 3)
			{
				playerMoveIndexes["row1"].push_back(moveIndex);
				return;
			}

			playerMoveIndexes["row2"].push_back(moveIndex);
			return;
		}

		playerMoveIndexes["row3"].push_back(moveIndex);
		return;
	}
}

bool TicTacToeEngine::checkWinCon(const char playerOrAI)
{
	// for an ai win check
	if (toupper(playerOrAI) == 'A')
	{
		for (auto& pair : AIMoveIndexes)
		{
			if (pair.second.size() == 3)
			{
				return true;
			}
		}
	}

	// for a player win check
	else if (toupper(playerOrAI) == 'P')
	{
		for (auto& pair : playerMoveIndexes)
		{
			if (pair.second.size() == 3)
			{
				return true;
			}
		}
	}

	return false;
}

int TicTacToeEngine::generateMove()
{
	//generate index of AI move within spotChoices
	int move = randomizer.generateNum(BOARD_SPACES_NUM - 1);

	std::cout << "Hmmmmm.....";
	std::this_thread::sleep_for(std::chrono::milliseconds(1200));

	//record move
	loadAIMove(spotChoices[move] - 1);

	int returnValue = (spotChoices[move] - 1);
	//remove move number from spotChoices
	spotChoices.erase(spotChoices.begin() + move);

	return (returnValue);
}

int TicTacToeEngine::readPlayerMove()
{
	for (int i = 0; i < 100; ++i)
	{
		int pMove;

		std::cout << "What is your move?  ";
		std::cin >> pMove;
		

		auto pMoveIndex = std::find(spotChoices.begin(), spotChoices.end(), pMove);
		if (pMoveIndex != spotChoices.end())
		{
			spotChoices.erase(pMoveIndex);
			loadPlayerMove(pMove - 1);
			return (pMove - 1);
		}

		std::cout << "Invalid spot, please pick a spot on the board that has not been chosen\n\n";
	}

	std::cout << "You are really somethin ay?";
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::exit(1);
}