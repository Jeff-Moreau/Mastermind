#include "NewGame.h"

NewGame::NewGame()
{
    mTotalGuesses = 0;
    mGuessCount = 0;
    mShowCode = false;
    mUserInput = "";
    p_mMiscFunctions = new MiscFunctions();
    p_mNewBoard = new GameBoard();
}

void NewGame::Start()
{
    system("CLS");
    mGameTitle.PrintTitle();
    CodemakerGuess();
    DisplayCodemakersGuessHidden();
    NewBoard();
    DisplayMyBoard();
    Prompt();
}

void NewGame::NewBoard()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            p_mNewBoard->GetBoard()->GuessBoard[i][j] = mPieces.OO;
        }
    }
}

void NewGame::CodemakerGuess()
{
    for (int i = 0; i < GUESSES; i++)
    {
        mCodemakerGuessPieces[i] = mPieces.AllPieces[rand() % 7 + 1];
    }
}

void NewGame::DisplayCodemakersGuess()
{
    p_mMiscFunctions->LineColor(RED);
    std::cout << "                                 CODEMAKERS CODE" << std::endl;
    p_mMiscFunctions->LineColor(PURPLE);
    std::cout << "                                   -----------" << std::endl;
    std::cout << "                                   | ";

    for (int i = 0; i < GUESSES; i++)
    {
        p_mMiscFunctions->LineColor(mCodemakerGuessPieces[i].color);
        std::cout << mCodemakerGuessPieces[i].icon;
        p_mMiscFunctions->LineColor(PURPLE);
        std::cout << " ";
    }

    std::cout << "|" << std::endl;
    std::cout << "                                   -----------" << std::endl;
}

void NewGame::DisplayCodemakersGuessHidden()
{
    p_mMiscFunctions->LineColor(RED);
    std::cout << "                                 CODEMAKERS CODE" << std::endl;
    p_mMiscFunctions->LineColor(PURPLE);
    std::cout << "                                   -----------" << std::endl;
    std::cout << "                                   | ";

    for (int i = 0; i < GUESSES; i++)
    {
        p_mMiscFunctions->LineColor(mPieces.OO.color);
        std::cout << mPieces.OO.icon;
        p_mMiscFunctions->LineColor(PURPLE);
        std::cout << " ";
    }

    std::cout << "|" << std::endl;
    std::cout << "                                   -----------" << std::endl;
}

void NewGame::DisplayMyBoard()
{
    p_mMiscFunctions->LineColor(GREENBRIGHT);
    std::cout << "                               CODEBREAKER GUESSES" << std::endl;
    p_mNewBoard->DisplayGameBoard(p_mNewBoard->GetBoard()->GuessBoard);
    std::cout << std::endl;
}

void NewGame::GetGuesses()
{
    for (int i = ROWS; i > 0; i--)
    {
        if (p_mNewBoard->GetBoard()->GuessBoard[i - 1][0].name == mPieces.OO.name)
        {
            for (int j = 0; j < COLS; j++)
            {
                p_mNewBoard->GetBoard()->GuessBoard[i - 1][j] = mMyGuessPieces[j];
            }
            break;  
        }
    }
}

void NewGame::Prompt()
{
    p_mMiscFunctions->LineColor(YELLOWBRIGHT);

    for (int i = 0; i < GUESSES; i++)
    {
        if (mMyGuessPieces[i].color == NULL)
        {
            std::cout << "                            Please enter your ";
            p_mMiscFunctions->LineColor(GREENBRIGHT);
            std::cout << "#" << i + 1;
            p_mMiscFunctions->LineColor(YELLOWBRIGHT);
            std::cout << " color.\n";
            std::cout << "                 Type the name of the color frrom the list Below.\n\n";
            break;
        }
    }

    if (mMyGuessPieces[3].color != NULL)
    {
        GetGuesses();
        HintsShown();
        mTotalGuesses++;
    }
    else
    {
        std::cout << "                                Color Choices are:\n";
        std::cout << "              ";
        for (int i = 0; i < mPieces.AllPieces.size(); i++)
        {
            p_mMiscFunctions->LineColor(mPieces.AllPieces[i].color);
            std::cout << mPieces.AllPieces[i].name;
            p_mMiscFunctions->LineColor(WHITEBRIGHT);
            std::cout << ", ";
        }

    }

    std::cout << std::endl << std::endl;
    std::cout << "| @ @ @ @ > :";
    std::getline(std::cin, mUserInput);
    GetInput();
}

void NewGame::GetInput()
{
    if (mUserInput.length() == 0)
    {
        Reload();
    }
    else if (!isdigit(mUserInput[0]))
    {
        if (mUserInput == "black" || mUserInput == "Black" || mUserInput == "bk" || mUserInput == "BK")
        {
            for (int i = 0; i < 4; i++)
            {
                if (mMyGuessPieces[i].color == NULL)
                {
                    mMyGuessPieces[i] = mPieces.BK;
                    mGuessCount++;
                    Reload();
                    break;
                }
            }
        }
        else if (mUserInput == "blue" || mUserInput == "Blue" || mUserInput == "bl" || mUserInput == "BL")
        {
            for (int i = 0; i < 4; i++)
            {
                if (mMyGuessPieces[i].color == NULL)
                {
                    mMyGuessPieces[i] = mPieces.BL;
                    mGuessCount++;
                    Reload();
                    break;
                }
            }
        }
        else if (mUserInput == "green" || mUserInput == "Green" || mUserInput == "gr" || mUserInput == "GR")
        {
            for (int i = 0; i < 4; i++)
            {
                if (mMyGuessPieces[i].color == NULL)
                {
                    mMyGuessPieces[i] = mPieces.GR;
                    mGuessCount++;
                    Reload();
                    break;
                }
            }
        }
        else if (mUserInput == "yellow" || mUserInput == "Yellow" || mUserInput == "ye" || mUserInput == "YE")
        {
            for (int i = 0; i < 4; i++)
            {
                if (mMyGuessPieces[i].color == NULL)
                {
                    mMyGuessPieces[i] = mPieces.YE;
                    mGuessCount++;
                    Reload();
                    break;
                }
            }
        }
        else if (mUserInput == "red" || mUserInput == "Red" || mUserInput == "rd" || mUserInput == "RD")
        {
            for (int i = 0; i < 4; i++)
            {
                if (mMyGuessPieces[i].color == NULL)
                {
                    mMyGuessPieces[i] = mPieces.RD;
                    mGuessCount++;
                    Reload();
                    break;
                }
            }
        }
        else if (mUserInput == "purple" || mUserInput == "Purple" || mUserInput == "pu" || mUserInput == "PU")
        {
            for (int i = 0; i < 4; i++)
            {
                if (mMyGuessPieces[i].color == NULL)
                {
                    mMyGuessPieces[i] = mPieces.PU;
                    mGuessCount++;
                    Reload();
                    break;
                }
            }
        }
        else if (mUserInput == "orange" || mUserInput == "Orange" || mUserInput == "or" || mUserInput == "OR")
        {
            for (int i = 0; i < 4; i++)
            {
                if (mMyGuessPieces[i].color == NULL)
                {
                    mMyGuessPieces[i] = mPieces.OR;
                    mGuessCount++;
                    Reload();
                    break;
                }
            }
        }
        else if (mUserInput == "white" || mUserInput == "White" || mUserInput == "wh" || mUserInput == "WH")
        {
            for (int i = 0; i < 4; i++)
            {
                if (mMyGuessPieces[i].color == NULL)
                {
                    mMyGuessPieces[i] = mPieces.WH;
                    mGuessCount++;
                    Reload();
                    break;
                }
            }
        }
        else if (mUserInput == "s" || mUserInput == "S")
        {
            mShowCode == false ? mShowCode = true : mShowCode = false;
            Reload();
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

void NewGame::Reload()
{
    system("CLS");
    mGameTitle.PrintTitle();
    mShowCode == true ? DisplayCodemakersGuess() : DisplayCodemakersGuessHidden();
    DisplayMyBoard();
    Prompt();
}

void NewGame::HintsShown()
{
    system("CLS");
    mGameTitle.PrintTitle();
    DisplayCodemakersGuessHidden();
    DisplayMyBoard();

    int correct = 0;
    int colorCorrect = 0;

    for (int i = 0; i < GUESSES; i++)
    {
        if (mMyGuessPieces[i].color == mCodemakerGuessPieces[i].color)
        {
            correct++;
        }
        else
        {
            for (int j = 0 + correct; j < GUESSES; j++)
            {
                if (mMyGuessPieces[i].color == mCodemakerGuessPieces[j].color)
                {
                    colorCorrect++;
                }
            }
        }
    }
    
    if (mTotalGuesses < 13 && correct == GUESSES)
    {
        system("CLS");
        mGameTitle.PrintTitle();
        DisplayCodemakersGuess();
        DisplayMyBoard();
        std::cout << "                          CONGO-RATS";
        mTotalGuesses = 0;
        CodemakerGuess();
        NewBoard();
    }
    else if (mTotalGuesses < 12)
    {
        p_mMiscFunctions->LineColor(WHITEBRIGHT);
        std::cout << "                      You got ";
        p_mMiscFunctions->LineColor(GREENBRIGHT);
        std::cout << correct;
        p_mMiscFunctions->LineColor(WHITEBRIGHT);
        std::cout << " Right in the Right Spot\n";

        std::cout << "                      You got ";
        p_mMiscFunctions->LineColor(YELLOWBRIGHT);
        std::cout << colorCorrect;
        p_mMiscFunctions->LineColor(WHITEBRIGHT);
        std::cout << " Right in the Wrong Spot.\n";
    }
    else
    {
        system("CLS");
        mGameTitle.PrintTitle();
        DisplayCodemakersGuess();
        DisplayMyBoard();
        std::cout << "                          YOU SUCK TRY AGAIN";
        mTotalGuesses = 0;
        CodemakerGuess();
        NewBoard();
    }

    for (int i = 0; i < GUESSES; i++)
    {
        mMyGuessPieces[i].color = NULL;
    }
}

NewGame::~NewGame()
{
    delete p_mMiscFunctions;
    p_mMiscFunctions = nullptr;
}