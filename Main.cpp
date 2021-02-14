#include "GameWindow.h"
#include <iostream>

int main(int argc, char *argv[])
{
     std::cout << "hey" << std::endl;
    GameWindow *TowerGame = new GameWindow();
    TowerGame->game_play();

    delete TowerGame;
    return 0;
}
