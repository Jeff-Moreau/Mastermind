#include "GamePieces.h"

GamePieces::GamePieces()
{
    p_mMiscFunctions = new MiscFunctions();

    BK.name = "Black";
    BK.color = GREY;
    BK.icon = "@";
    AllPieces.push_back(BK);

    BL.name = "Blue";
    BL.color = BLUEBRIGHT;
    BL.icon = "@";
    AllPieces.push_back(BL);

    GR.name = "Green";
    GR.color = GREENBRIGHT;
    GR.icon = "@";
    AllPieces.push_back(GR);
    
    YE.name = "Yellow";
    YE.color = YELLOWBRIGHT;
    YE.icon = "@";
    AllPieces.push_back(YE);

    RD.name = "Red";
    RD.color = REDBRIGHT;
    RD.icon = "@";
    AllPieces.push_back(RD);

    PU.name = "Purple";
    PU.color = PURPLEBRIGHT;
    PU.icon = "@";
    AllPieces.push_back(PU);

    OR.name = "Orange";
    OR.color = YELLOW;
    OR.icon = "@";
    AllPieces.push_back(OR);

    WH.name = "White";
    WH.color = WHITEBRIGHT;
    WH.icon = "@";
    AllPieces.push_back(WH);

    OO.name = "Blank";
    OO.color = WHITE;
    OO.icon = ".";
}

GamePieces::~GamePieces()
{
    delete p_mMiscFunctions;
    p_mMiscFunctions = nullptr;
}
