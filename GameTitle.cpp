#include "GameTitle.h"

GameTitle::GameTitle()
{
    p_mMiscFunctions = new MiscFunctions();
}

void GameTitle::PrintTitle()
{
    p_mMiscFunctions->LineColor(PURPLEBRIGHT);
    std::cout << "\n";
    std::cout << "           @   @  @@@   @@@@ @@@@@  @@@@ @@@@  @   @ @@@@@ @   @ @@@@\n";
    std::cout << "           @@ @@ @   @ @       @   @     @   @ @@ @@   @   @@  @ @   @\n";
    std::cout << "           @ @ @ @@@@@ @@@@@   @   @@@@  @@@@  @ @ @   @   @ @ @ @   @\n";
    std::cout << "           @   @ @   @     @   @   @     @   @ @   @   @   @  @@ @   @\n";
    std::cout << "           @   @ @   @ @@@@    @    @@@@ @   @ @   @ @@@@@ @   @ @@@@\n\n";
    p_mMiscFunctions->LineColor(WHITEBRIGHT);
}

GameTitle::~GameTitle()
{
    delete p_mMiscFunctions;
    p_mMiscFunctions = nullptr;
}