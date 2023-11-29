#ifndef GAME_TITLE_H
#define GAME_TITLE_H

#include <Windows.h>
#include <iostream>
#include <string>

#include "MiscFunctions.h"

class GameTitle
{
private:
    MiscFunctions* p_mMiscFunctions;

public:
    GameTitle();
    ~GameTitle();

public:
    void PrintTitle();
};
#endif // !GAME_TITLE_H