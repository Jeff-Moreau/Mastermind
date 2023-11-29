#include <iostream>
#include <string>
#include "GameLoop.h"

const int WIDTH = 700;
const int HEIGHT = 600;

int main()
{
    srand(time(NULL));

    HWND newWindow = GetConsoleWindow();
    RECT resize;

    GetWindowRect(newWindow, &resize);
    MoveWindow(newWindow, resize.left, resize.top, WIDTH, HEIGHT, TRUE);

    GameLoop mainLoop;

    return 80081355;
}