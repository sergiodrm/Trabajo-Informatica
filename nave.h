#ifndef NAVE_H
#define NAVE_H
#include <string.h>
#include <iostream>

using namespace std;

class Nave{

private:
    // Aquí iría la imagen
    int vida;
    int escudo;
    int ataque;
    int ataque_especial;
    pair <int, int> pos;

public:
    Nave();
    Nave(int vida, int esc, int ataq, int ataq_es, pair<int, int> posic);
    ~Nave();

    int getVida();
    int getAtaque();
    int getAtaque_especial();
    int getEscudo();
    pair <int,int> getPos();

    void setVida(int value);
    void setAtaque(int value);
    void setAtaque_especial(int value);
    void setEscudo(int value);
    void setPos(pair <int,int> new_pos);

    void mover();
    void atacar(Nave *);

};
