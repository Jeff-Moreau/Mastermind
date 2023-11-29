#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <iostream>

#include "GamePieces.h"

const int ROWS = 12;
const int COLS = 4;

class GameBoard
{
private: 
    struct Board
    {
        GamePieces P;
        Pieces GuessBoard[ROWS][COLS] ={ {P.OO,P.OO,P.OO,P.OO},
                                         {P.OO,P.OO,P.OO,P.OO},
                                         {P.OO,P.OO,P.OO,P.OO},
                                         {P.OO,P.OO,P.OO,P.OO},
                                         {P.OO,P.OO,P.OO,P.OO},
                                         {P.OO,P.OO,P.OO,P.OO},
                                         {P.OO,P.OO,P.OO,P.OO},
                                         {P.OO,P.OO,P.OO,P.OO},
                                         {P.BK,P.WH,P.OR,P.GR},
                                         {P.BK,P.WH,P.GR,P.OR},
                                         {P.BK,P.BK,P.PU,P.OR},
                                         {P.BK,P.BL,P.RD,P.YE} };
    };

private:
    MiscFunctions* p_mMiscFunctions;
    Board* p_mBoard;

public:
    GameBoard();
    ~GameBoard();

public:
    Board* GetBoard() { return p_mBoard; }

    void DisplayGameBoard(const Pieces[ROWS][COLS]);
};
#endif // !GAME_BOARD_H