#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "GameTitle.h"
#include "GameBoard.h"
#include "NewGame.h"

class GameLoop
{
private:
    MiscFunctions* p_mMiscFunctions;
    NewGame* p_mGame;

    GameTitle mGameTitle;
    GameBoard mGameBoard;
    std::string mUserInput;

public:
    GameLoop();
    ~GameLoop();

public:
    void Start();
    void Description();
    void MenuOptions();
    void GetInput();
    void Instructions();
};
#endif // !GAME_LOOP_H