#include "GameBoard.h"

GameBoard::GameBoard()
{
    p_mMiscFunctions = new MiscFunctions();
    p_mBoard = new Board();
}

void GameBoard::DisplayGameBoard(const Pieces[ROWS][COLS])
{
    // these loops are used to get the color of each piece on the gameboard
    // and then print out the icon.
    p_mMiscFunctions->LineColor(PURPLE);
    std::cout << "                                   -----------" << std::endl;
    for (int i = 0; i < ROWS; i++)
    {
        std::cout << "                                   | ";
        for (int j = 0; j < COLS; j++)
        {
            p_mMiscFunctions->LineColor(p_mBoard->GuessBoard[i][j].color);
            std::cout << p_mBoard->GuessBoard[i][j].icon;
            p_mMiscFunctions->LineColor(PURPLE);
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "                                   -----------" << std::endl;
}

GameBoard::~GameBoard()
{
    delete p_mMiscFunctions;
    p_mMiscFunctions = nullptr;
}