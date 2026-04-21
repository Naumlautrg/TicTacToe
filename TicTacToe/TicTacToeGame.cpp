#include "TicTacToeGame.h"
#include "TicTacToeAI.h"
#include "TicTacToeEngineButBetter.h"

void TicTacToeGame::startGame()
{
	
	std::cout << "\n\nReady to play? (Y/N):  ";
	std::cin >> play;
	
	while (std::toupper(play) != 'Y' && std::toupper(play) != 'N')
	{
		std::cout << "\n\nPlease enter either 'Y' or 'N'\n";
		std::cout << "Ready to play? (Y/N):  ";
		std::cin >> play;
	}


	//playGameSimple();
	playGameHard();

	std::cout << "\n\nFarewell";
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void TicTacToeGame::printStartBoard()
{
	system("cls");
	
	currentBoard = startBoard;

	std::cout << "Board Layout:\n"; // " 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n\n";
	for (int i = 0; i < startBoard.size(); ++i)
	{
		std::cout << " " << startBoard[i] << " ";
		if ((((i + 1) % 3) == 0) && (i != 8))
		{
			std::cout << "\n-----------\n";
		}

		else if (i != 8)
		{
			std::cout << "|";
		}
	}
	std::cout << "\n\n";
}

void TicTacToeGame::updateBoard(int moveIndex, const char playerOrAI)
{
	system("cls");

	if (playerOrAI == 'A')
	{
		currentBoard[moveIndex] = 'X';
	}

	else
	{
		currentBoard[moveIndex] = 'O';
	}


	//print the updated board
	for (int i = 0; i < currentBoard.size(); ++i)
	{
		std::cout << " " << currentBoard[i] << " ";
		if ((((i + 1) % 3) == 0) && (i != 8))
		{
			std::cout << "\n-----------\n";
		}

		else if (i != 8)
		{
			std::cout << "|";
		}
	}

	std::cout << "\n\n";
}

void TicTacToeGame::playGameSimple()
{
	//Keep going so long as Player wants to play
	while (std::toupper(play) == 'Y')
	{
		gameWon = false;
		printStartBoard();
		TicTacToeEngine steve;
		int firstPlay = steve.generateNum(1);



		//std::cout << "Let's play\n\n";


		//If AI goes first:
		if (firstPlay == 0)
		{
			std::cout << "I will go first.\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1200));

			while (!steve.spotChoices.empty())
			{
				int aMove = steve.generateMove();
				//get AI move and check win con
				updateBoard(aMove, 'A');

				if (steve.checkWinCon('A'))
				{
					gameWon = true;
					std::cout << "YAY!! I Win!!\n\n";
					std::cout << "Would you like to play again? (Y/N)  ";
					std::cin >> play;
					std::cout << "\n\n";
					break;
				}

				//get Player move and check win con
				if (!steve.spotChoices.empty())
				{
					int pMove = steve.readPlayerMove();
					updateBoard(pMove, 'P');
				}

				if (steve.checkWinCon('P'))
				{
					gameWon = true;
					std::cout << "Congrats!! You Win!!\n\n";
					std::cout << "Would you like to play again? (Y/N)  ";
					std::cin >> play;
					std::cout << "\n\n";
					break;
				}

			}
		}


		//If Player goes first:
		if (firstPlay == 1)
		{
			std::cout << "You go first.\n\n";

			while (!steve.spotChoices.empty())
			{
				int pMove = steve.readPlayerMove();
				updateBoard(pMove, 'P');
				if (steve.checkWinCon('P'))
				{
					gameWon = true;
					std::cout << "Coongrats!! You Win!!\n\n";
					std::cout << "Would you like to play again? (Y/N)  ";
					std::cin >> play;
					std::cout << "\n\n";
					break;
				}

				if (!steve.spotChoices.empty())
				{
					int aMove = steve.generateMove();
					
					updateBoard(aMove, 'A');
				}

				if (steve.checkWinCon('A'))
				{
					gameWon = true;
					std::cout << "YAY!! I Win!!\n\n";
					std::cout << "Would you like to play again? (Y/N)  ";
					std::cin >> play;
					std::cout << "\n\n";
					break;
				}
			}
		}

		if (!gameWon) //(!(steve.checkWinCon('A') && steve.checkWinCon('P')))
		{
			std::cout << "Cat's game...\nWould you like to play again? (Y/N):  ";
			std::cin >> play;
			std::cout << "\n\n\n";
		}

	}
}

void TicTacToeGame::playGameHard()
{
	//Keep going so long as Player wants to play
	while (std::toupper(play) == 'Y')
	{
		gameWon = false;
		printStartBoard();
		TicTacToeEngineButBetter eugene;
		int firstPlay = eugene.decideFirstPlay();



		//std::cout << "Let's play\n\n";


		//If AI goes first:
		if (firstPlay == 0)
		{
			std::cout << "I will go first.\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));

			while (!eugene.isFull())
			{
				int aMove = eugene.getBestMove();
				//get AI move and check win con
				updateBoard(aMove, 'A');

				if (eugene.checkWin() == eugene.AI)
				{
					gameWon = true;
					std::cout << "YAY!! I Win!!\n\n";
					play = playAgain();
					std::cout << "\n\n";
					break;
				}

				//get Player move and check win con
				if (!eugene.isFull())
				{
					int pMove = eugene.readPlayerMove();
					updateBoard(pMove, 'P');
				}

				if (eugene.checkWin() == eugene.HUMAN)
				{
					gameWon = true;
					std::cout << "Congrats!! You Win!!\n\n";
					play = playAgain();
					std::cout << "\n\n";
					break;
				}

			}
		}


		//If Player goes first:
		else if (firstPlay == 1)
		{
			std::cout << "You go first.\n\n";

			while (!eugene.isFull())
			{
				int pMove = eugene.readPlayerMove();
				updateBoard(pMove, 'P');
				if (eugene.checkWin() == eugene.HUMAN)
				{
					gameWon = true;
					std::cout << "Coongrats!! You Win!!\n\n";
					play = playAgain();
					std::cout << "\n\n";
					break;
				}

				if (!eugene.isFull())
				{
					int aMove = eugene.getBestMove();

					updateBoard(aMove, 'A');
				}

				if (eugene.checkWin() == eugene.AI)
				{
					gameWon = true;
					std::cout << "YAY!! I Win!!\n\n";
					play = playAgain();
					std::cout << "\n\n";
					break;
				}
			}
		}

		if (!gameWon) //(!(steve.checkWinCon('A') && steve.checkWinCon('P')))
		{
			std::cout << "Cat's game...\n";
			play = playAgain();
			std::cout << "\n\n";
		}

	}
	


}

char TicTacToeGame::playAgain()
{
	std::cout << "Would you like to play again? (Y/N)  ";
	std::cin >> play;

	while (std::toupper(play) != 'Y' && std::toupper(play) != 'N')
	{
		std::cout << "\n\nPlease enter either 'Y' or 'N'\n";
		std::cout << "Would you like to play again? (Y/N):  ";
		std::cin >> play;
	}

	return play;
}
