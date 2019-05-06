#include "menuwindow.h"
#include <QApplication>
#include <game.h>
#include <windows.h>
#include <iostream>

using namespace std;

//template <class N> class myGame;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MenuWindow menu;

    menu.show();

    while ( !menu.isHidden() ) {
        a.processEvents();
        Sleep(100);
    }

    if ( menu.getJugar() )
    {
        if ( menu.getTipo() == Tipo::tipo_acorazado ) {
            Game<Acorazado> my_game;
            my_game.iniciarGame(&a);
        } else if ( menu.getTipo() == Tipo::tipo_caza ) {
            Game<Caza> my_game;
            my_game.iniciarGame(&a);
        } else if ( menu.getTipo() == Tipo::tipo_destructor ) {
            Game<Destructor> my_game;
            my_game.iniciarGame(&a);
        } else if ( menu.getTipo() == Tipo::tipo_warship ) {
            Game<Warship> my_game;
            my_game.iniciarGame(&a);
        }
    }



    cout << "Fin del programa." << endl;
    return 0;
}
