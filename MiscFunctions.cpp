#include "MiscFunctions.h"

MiscFunctions::MiscFunctions()
{

}

MiscFunctions::~MiscFunctions()
{

}

void MiscFunctions::LineColor(int color)
{
    SetConsoleTextAttribute(mCharacter, color);
}

