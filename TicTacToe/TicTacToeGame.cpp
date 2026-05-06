#include "TicTacToeGame.h"

#include "TicTacToeEngine.h"
#include "TicTacToeEngineButBetter.h"

TicTacToeGame::TicTacToeGame()
{
	currentBoard = startBoard;
}

void TicTacToeGame::startGame()
{
	char input;
	std::cout << "Ready to play? (Y/N):  ";
	std::cin >> input;
	
	while (std::toupper(input) != TicTacToeConstants::CIN_YES && std::toupper(input) != TicTacToeConstants::CIN_YES)
	{
		std::cout << "\n\nPlease enter either 'Y' or 'N'\n";
		std::cout << "Ready to play? (Y/N):  ";
		std::cin >> input;
	}

	if (std::toupper(input) == TicTacToeConstants::CIN_YES)
	{
		playGameSimple();
		//playGameHard();
	}
	else
	{
		std::cout << "\n\nFarewell";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void TicTacToeGame::printStartBoard()
{
	currentBoard = startBoard;

	system("cls");
	printCurrentBoard();
}

void TicTacToeGame::printCurrentBoard() const
{
	std::cout << "Board Layout:\n"; // " 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n\n";
	for (int i = 0; i < currentBoard.size(); ++i)
	{
		std::cout << " " << currentBoard[i] << " ";

		int boardPosition = i + 1;

		if (boardPosition % 3 == 0 && boardPosition != 9)
			std::cout << "\n-----------\n";
		else if (boardPosition != 9)
			std::cout << "|";
	}
	std::cout << "\n\n";
}

void TicTacToeGame::updateBoard(int moveIndex, const PlayerType type)
{
	system("cls");

	if (type == PlayerType::AI)
	{
		currentBoard[moveIndex] = TicTacToeConstants::MOVE_AI;
	}

	else if (type == PlayerType::Player)
	{
		currentBoard[moveIndex] = TicTacToeConstants::MOVE_HUMAN;
	}

	printCurrentBoard();
}

void TicTacToeGame::playGameSimple()
{
	char play = TicTacToeConstants::CIN_YES;
	//Keep going so long as Player wants to play
	while (std::toupper(play) == TicTacToeConstants::CIN_YES)
	{
		gameWon = false;
		printStartBoard();
		TicTacToeEngine steve;

		// true = player goes first, false = AI goes first
		bool turn = steve.randomizer.generateNum(0, 1) == static_cast<int>(PlayerType::Player);
		// Ternary expression to cout the correct phrase in either case
		std::cout << (turn ? "You go first.\n\n" : "I will go first.\n\n");

		while (steve.movesAvailable())
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));

			if (turn)
			{
				int playerMove = steve.readPlayerMove();
				updateBoard(playerMove, PlayerType::Player);

				if (steve.checkWinCon(PlayerType::Player))
				{
					gameWon = true;
					std::cout << "Congrats!! You Win!!\n\n";
					break;
				}
			}
			else
			{
				int AIMove = steve.generateMove();
				updateBoard(AIMove, PlayerType::AI);

				if (steve.checkWinCon(PlayerType::AI))
				{
					gameWon = true;
					std::cout << "YAY!! I Win!!\n\n";
					break;
				}
			}

			turn = !turn;
		}

		if (!gameWon)
		{
			std::cout << "Cat's game...\n\n";
		}

		play = playAgain();
	}
}

void TicTacToeGame::playGameHard()
{
	char play = TicTacToeConstants::CIN_YES;
	//Keep going so long as Player wants to play
	while (std::toupper(play) == TicTacToeConstants::CIN_YES)
	{
		gameWon = false;
		printStartBoard();
		TicTacToeEngineButBetter eugene;
		int firstPlay = eugene.decideFirstPlay();

		//If AI goes first:
		if (firstPlay == 0)
		{
			std::cout << "I will go first.\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));

			while (!eugene.isFull())
			{
				int aMove = eugene.getBestMove();
				//get AI move and check win con
				updateBoard(aMove, PlayerType::AI);

				if (eugene.checkWin() == TicTacToeConstants::MOVE_AI)
				{
					gameWon = true;
					std::cout << "YAY!! I Win!!\n\n";
					break;
				}

				//get Player move and check win con
				if (!eugene.isFull())
				{
					int pMove = eugene.readPlayerMove();
					updateBoard(pMove, PlayerType::Player);
				}

				if (eugene.checkWin() == TicTacToeConstants::MOVE_HUMAN)
				{
					gameWon = true;
					std::cout << "Congrats!! You Win!!\n\n";
					break;
				}
			}

			if (!gameWon)
			{
				std::cout << "Cat's game...\n";
			}

			play = playAgain();
			std::cout << "\n\n";
		}

		//If Player goes first:
		else if (firstPlay == 1)
		{
			std::cout << "You go first.\n\n";

			while (!eugene.isFull())
			{
				int pMove = eugene.readPlayerMove();
				updateBoard(pMove, PlayerType::Player);
				if (eugene.checkWin() == TicTacToeConstants::MOVE_HUMAN)
				{
					gameWon = true;
					std::cout << "Coongrats!! You Win!!\n\n";
					break;
				}

				if (!eugene.isFull())
				{
					int aMove = eugene.getBestMove();

					updateBoard(aMove, PlayerType::AI);
				}

				if (eugene.checkWin() == TicTacToeConstants::MOVE_AI)
				{
					gameWon = true;
					std::cout << "YAY!! I Win!!\n\n";
					break;
				}
			}

			if (!gameWon)
			{
				std::cout << "Cat's game...\n";
			}

			play = playAgain();
			std::cout << "\n\n";
		}
	}
}

char TicTacToeGame::playAgain()
{
	char input = ' ';
	std::cout << "Would you like to play again? (Y/N)  ";
	std::cin >> input;

	while (std::toupper(input) != TicTacToeConstants::CIN_YES 
		&& std::toupper(input) != TicTacToeConstants::CIN_NO)
	{
		std::cout << "\n\nPlease enter either 'Y' or 'N'\n";
		std::cout << "Would you like to play again? (Y/N):  ";
		std::cin >> input;
	}

	return input;
}
