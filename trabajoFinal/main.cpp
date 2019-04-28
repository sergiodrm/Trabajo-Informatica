#include "menuwindow.h"
#include <QApplication>
#include "game.h"
#include <windows.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Game my_game;

    my_game.initGame();

    while ( !my_game.getGameOver() ) {
        a.processEvents();
        my_game.actualizarGame();
        Sleep(50);
    }

    cout << "Fin del programa." << endl;

    return 0;
}
