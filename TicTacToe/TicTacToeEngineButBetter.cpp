#include "TicTacToeEngineButBetter.h"
#include "Random.h"
#include <thread>
#include <chrono>

char TicTacToeEngineButBetter::checkWin()
{
    const int winCon[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for (auto& line : winCon)
    {
        char a = board[line[0]];
        char b = board[line[1]];
        char c = board[line[2]];
        
        if (a != EMPTY && a == b && b == c)
        {
            return a;
        }
    }

    return EMPTY;
}

bool TicTacToeEngineButBetter::isFull()
{
    for (char spot : board)
    {
        if (spot == EMPTY)
        {
            return false;
        }        
    }

    return true;
}

std::vector<int> TicTacToeEngineButBetter::getLegalMoves()
{
    std::vector<int> legalMoves;

    for (int i = 0; i < board.size(); ++i)
    {
        if (board[i] == EMPTY)
        {
            legalMoves.push_back(i);
        }
    }

    return legalMoves;
}

int TicTacToeEngineButBetter::decideFirstPlay()
{
    return Random().generateNum(1);
}

int TicTacToeEngineButBetter::getBestMove()
{
    int bestScore = -10000;
    int bestMove = -1;

    for (int move : getLegalMoves())
    {
        board[move] = AI; //load theoretical move to start minimax
        int score = minimax(false, 0); // start minimax
        board[move] = EMPTY; // return to initial condition

        if (score > bestScore)
        {
            bestScore = score;
            bestMove = move;
        }
    }

    board[bestMove] = AI;

    return bestMove;
}

int TicTacToeEngineButBetter::readPlayerMove()
{
    std::vector<int> moves = getLegalMoves();

    for (int i = 0; i < 100; ++i)
    {
        int pMove;

        std::cout << "What is your move?  ";
        std::cin >> pMove;



        auto pMoveIndex = std::find(moves.begin(), moves.end(), (pMove - 1));
        if (pMoveIndex != moves.end())
        {
            board[(pMove - 1)] = HUMAN;
            return (pMove - 1);
        }

        std::cout << "Invalid spot, please pick a spot on the board that has not been chosen\n\n";

    }

    std::cout << "You are really somethin ay?";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::exit(1);
}

int TicTacToeEngineButBetter::minimax(bool isMaximizing, int depth)
{
    
    // when reaching a terminating condition retrun evaluation
    // depth gives weight to fastest wins and slowest losses
    char winner = checkWin();
    if (winner == AI) { return 10 - depth; }
    if (winner == HUMAN) { return -10 + depth; }
    if (isFull()) { return 0; }


    if (isMaximizing)
    {
        int best = -10000;

        for (int move : getLegalMoves())
        {
            board[move] = AI; // load theoretical AI move
            best = std::max(best, minimax(false, depth + 1)); //start evaluation of said move
            board[move] = EMPTY; // return board to initial state
        }

        return best;
    }

    else
    {
        int best = 10000;

        for (int move : getLegalMoves())
        {
            board[move] = HUMAN; // load theoretical HUMAN move
            best = std::min(best, minimax(true, depth + 1)); //start elav of said move
            board[move] = EMPTY; // return board to initial state
        }

        return best;
    }

}
