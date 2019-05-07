#ifndef GAME_H
#define GAME_H

#include "gamewindow.h"
#include "menuwindow.h"


class Game
{
public:
    Game();


    GameWindow getGameWindow();
    MenuWindow getMenuWindow();

    bool getGameOver();
    void setGameOver(bool game_over);

    void initGame();
    void actualizarGame();

private:
    GameWindow gamewindow;
    MenuWindow menuwindow;


    bool game_over;
};

#endif // GAME_H
