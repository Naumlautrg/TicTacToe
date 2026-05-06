# Naumlautrg TicTacToe Edit<br>
Majority of changes are simply refactoring code to personal preference.<br>
Main Highlights:
* Project now uses C++17
* Random implemented into TicTacToeEngine and TicTacToeEngineButBetter via composition as opposed to inheritance
* Char literals for Player ('P') and AI ('A') in TicTacToeEngine replaced with PlayerType enum class (located in new header file TicTacToeEnums.h)
* Required constants moved to new header file TicTacToeConstants.h
* Optimizations made to class TicTacToeEngine, including some from class TicTacToeEngineButBetter
