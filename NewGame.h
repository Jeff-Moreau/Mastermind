#ifndef NEW_GAME_H
#define NEW_GAME_H

#include <Windows.h>
#include <iostream>
#include <string>

#include "MiscFunctions.h"
#include "GameBoard.h"
#include "GameTitle.h"

const int GUESSES = 4;

class NewGame
{
private:
    int mTotalGuesses;
    int mGuessCount;
    bool mShowCode;
    std::string mUserInput;
    GameTitle mGameTitle;
    GamePieces mPieces;
    Pieces mCodemakerGuessPieces[4];
    Pieces mMyGuessPieces[4];

    MiscFunctions* p_mMiscFunctions;
    GameBoard* p_mNewBoard;

public:
    NewGame();
    ~NewGame();

public:
    void Start();
    void NewBoard();
    void CodemakerGuess();
    void DisplayCodemakersGuess();
    void DisplayCodemakersGuessHidden();
    void DisplayMyBoard();
    void GetGuesses();
    void Prompt();
    void GetInput();
    void Reload();
    void HintsShown();
};
#endif // !NEW_GAME_H