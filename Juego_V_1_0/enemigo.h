#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <iostream>
#include <time.h>
#include "nave.h"
#include "gamewindow.h"


using namespace std;

class Enemigo : virtual public Nave
{
public:
    Enemigo();
    void mover(Nave *jugador, vector<pair<int, int>> pos_bloq, vector<pair<int, int>> pos_en);


    int getRango_vision();
    void setRango_vision(int r);

    int getId();
    void setId(int id);
protected:
    int rango_vision;
    int id;
};

#endif // ENEMIGO_H
