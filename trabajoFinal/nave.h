#ifndef NAVE_H
#define NAVE_H

#include <vector>
#include <string.h>
#include <QPixmap>
#include <QDir>
#include <iostream>

using namespace std;

class Nave{

private:
    string nombre;
    QPixmap imagen;
    int vida;
    int escudo;
    int ataque;
    int ataque_especial;
    pair <int, int> pos;

public:
    Nave();
    Nave(int vida, int esc, int ataq, int ataq_es, pair<int, int> posic, QString path_image);
    ~Nave();

    int getVida();
    int getAtaque();
    int getAtaque_especial();
    int getEscudo();
    pair <int,int> getPos();
    QPixmap getImagen();

    void setVida(int value);
    void setAtaque(int value);
    void setAtaque_especial(int value);
    void setEscudo(int value);
    void setPos(pair <int,int> new_pos);
    int setDanno(Nave *mi_nave, bool tipo_ataque);

    void mover(char mov);
    void atacar(Nave *nave_enemiga);

};

#endif
