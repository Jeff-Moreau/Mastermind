#include "GameLoop.h"

GameLoop::GameLoop()
{
    p_mMiscFunctions = new MiscFunctions();
    p_mGame = new NewGame();

    mUserInput = "";

    Start();
}

void GameLoop::Start()
{
    system("CLS");
    mGameTitle.PrintTitle();
    Description();
    mGameBoard.DisplayGameBoard(mGameBoard.GetBoard()->GuessBoard);
    MenuOptions();
}

void GameLoop::Description()
{
    std::cout << " Mastermind is a game of skill, in which you engage in a battle of wits and logic.\n";
    std::cout << " The computer will be the";
    p_mMiscFunctions->LineColor(REDBRIGHT);
    std::cout << " Codemaker";
    p_mMiscFunctions->LineColor(WHITEBRIGHT);
    std::cout << ". It will create then hide a secret color code.\n";
    std::cout << "               You the";
    p_mMiscFunctions->LineColor(GREENBRIGHT);
    std::cout << " Codebreaker";
    p_mMiscFunctions->LineColor(WHITEBRIGHT);
    std::cout << ", must attempt to crack the code.              \n\n";
}

void GameLoop::MenuOptions()
{
    p_mMiscFunctions->LineColor(WHITEBRIGHT);
    std::cout << "\n";
    std::cout << "                                   (";
    p_mMiscFunctions->LineColor(GREENBRIGHT);
    std::cout << "N";
    p_mMiscFunctions->LineColor(WHITEBRIGHT);
    std::cout << ")ew Game                                    \n";
    std::cout << "                                 (";
    p_mMiscFunctions->LineColor(YELLOWBRIGHT);
    std::cout << "I";
    p_mMiscFunctions->LineColor(WHITEBRIGHT);
    std::cout << ")nstructions                                  \n";
    std::cout << "                                     (";
    p_mMiscFunctions->LineColor(RED);
    std::cout << "E";
    p_mMiscFunctions->LineColor(WHITEBRIGHT);
    std::cout << ")xit                                      \n\n";
    std::cout << "| @ @ @ @ > :";
    std::getline(std::cin, mUserInput);
    GetInput();
}

void GameLoop::GetInput()
{
    if (mUserInput.length() == 0)
    {
        Start();
    }
    else if (!isdigit(mUserInput[0]))
    {
        if (mUserInput == "n" || mUserInput == "N")
        {
            p_mGame->Start();
        }
        else if (mUserInput == "i" || mUserInput == "I")
        {
            Instructions();
        }
        else if (mUserInput == "e" || mUserInput == "E")
        {
            return;
        }
        else
        {
            p_mMiscFunctions->LineColor(REDBRIGHT);
            std::cout << "Please enter one of the menu choices!  ";
            p_mMiscFunctions->LineColor(YELLOWBRIGHT);
            system("pause");
            Start();
        }
    }
    else
    {
        p_mMiscFunctions->LineColor(REDBRIGHT);
        std::cout << "Please enter one of the menu choices!  ";
        p_mMiscFunctions->LineColor(YELLOWBRIGHT);
        system("pause");
        Start();
    }
}

void GameLoop::Instructions()
{
    mUserInput = "";

    system("CLS");
    mGameTitle.PrintTitle();

    p_mMiscFunctions->LineColor(YELLOW);
    std::cout << "                                   INSTRUCTIONS                              \n\n";
    p_mMiscFunctions->LineColor(WHITEBRIGHT);
    std::cout << "       You will be asked to enter 4 colors of pegs in order. One at a time.\n";
    std::cout << "           The first one will be Column 1, in the closest Row to you.\n";
    std::cout << "     Next will be the second spot to the right, then the third, then the last.\n";
    std::cout << "    After you enter the 4 colors it will appear on the screen and let you know\n";
    std::cout << "                   how close to the Codemakers code you were.\n\n";
    std::cout << "          You will also be givin hints along the way, so pay ATTENTION!\n\n";
    std::cout << "               You then try again, until you have filled the board.\n";
    std::cout << "      If you guess the Codemakers code before you reach all guesses, you WIN.\n\n";
    std::cout << "                               Otherwise you SUCK!\n\n";

    p_mMiscFunctions->LineColor(YELLOWBRIGHT);
    system("pause");
    Start();
}

GameLoop::~GameLoop()
{
    delete p_mMiscFunctions;
    p_mMiscFunctions = nullptr;

    delete p_mGame;
    p_mGame = nullptr;
}