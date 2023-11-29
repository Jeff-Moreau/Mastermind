#ifndef MISC_FUNCTIONS_H
#define MISC_FUNCTIONS_H

#include <windows.h>
#include <iostream>
#include <string>

    const enum Color
    {
        BLUE = 1,
        GREEN,
        AQUA,
        RED,
        PURPLE,
        YELLOW,
        WHITE,
        GREY,
        BLUEBRIGHT,
        GREENBRIGHT,
        AQUABRIGHT,
        REDBRIGHT,
        PURPLEBRIGHT,
        YELLOWBRIGHT,
        WHITEBRIGHT
    };

class MiscFunctions
{
private:
    HANDLE mCharacter = GetStdHandle(STD_OUTPUT_HANDLE);

public:
    MiscFunctions();
    ~MiscFunctions();
    void LineColor(int color);
};
#endif // !MISC_FUNCTIONS_H