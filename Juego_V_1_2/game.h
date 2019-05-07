#ifndef GAME_H
#define GAME_H

#include "gamewindow.h"
#include "menuwindow.h"
#include "enemigoacorazado.h"
#include "enemigocaza.h"
#include "enemigodestructor.h"
#include "enemigowarship.h"
#include <QApplication>
#include <windows.h>
#include <QKeyEvent>
#include <time.h>

#include <iostream>
using namespace std;

template <class N>
class Game
{
public:
    Game();
    GameWindow getGameWindow();


    bool getGameOver();
    void setGameOver(bool game_over);

    N getJugador();
    void setJugador(N jugador);

    bool comprobarPosicion(int mov);

    void mostrarMensaje(QString mensaje);

    void actualizarGame();

    void iniciarGame(QApplication *a);

    bool distancia(pair <int, int>, pair <int, int>);



private:

    GameWindow gamewindow;

    bool game_over;
    N jugador;
    int turno;
    bool hab_cerrojo1;
    bool hab_cerrojo2;

    // Variables de control de bloqueos
    const int n_bloqueos = 10;
    vector< pair<int, int> > bloqueos;

    // Variables de control de misiones
    const int n_misiones = 2;
    vector< pair<int, int> > misiones;
    bool mision_recogida;

    /* Un enemigo de cada tipo */
    const int n_enemigos = 4;
    EnemigoAcorazado enemy_acorazado;
    EnemigoCaza enemy_caza;
    EnemigoDestructor enemy_destructor;
    EnemigoWarship enemy_warship;
};

#endif // GAME_H
