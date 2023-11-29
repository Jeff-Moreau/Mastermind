#ifndef GAME_PIECES_H
#define GAME_PIECES_H

#include <Windows.h>
#include <iostream>
#include <vector>

#include "MiscFunctions.h"

struct Pieces
{
    std::string name;
    int color;
    std::string icon;
};

class GamePieces
{
public:
    Pieces BK; // Black
    Pieces BL; // Blue
    Pieces GR; // Green
    Pieces YE; // Yellow
    Pieces RD; // Red
    Pieces PU; // Purple
    Pieces OR; // Orange
    Pieces WH; // White
    Pieces OO; // Blank

    std::vector<Pieces> AllPieces;

private:
    MiscFunctions* p_mMiscFunctions;

public:
    GamePieces();
    ~GamePieces();
};
#endif // !GAME_PIECES_H