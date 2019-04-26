#ifndef NAVE_H
#define NAVE_H

#include <string.h>
#include <QPixmap>
#include <QLabel>
#include <QDir>
#include <iostream>

using namespace std;

class Nave{

private:
    QPixmap imagen;
    QLabel layout;
    int vida;
    int escudo;
    int ataque;
    int ataque_especial;
    pair <int, int> pos;

public:
    Nave();
    Nave(int vida, int esc, int ataq, int ataq_es, pair<int, int> posic, QString path_image, QWidget* parent);
    Nave(QWidget *parent, QString path, int vida = 50, int escudo = 20, int ataque = 4, int ataque_especial = 4, pair<int, int> pos = make_pair(0,0));
    Nave(Nave &n);
    ~Nave();

    int getVida();
    int getAtaque();
    int getAtaque_especial();
    int getEscudo();
    pair <int,int> getPos();
    QPixmap getImagen();
    //QLabel getLayout();
    int getX();
    int getY();

    void setVida(int value);
    void setAtaque(int value);
    void setAtaque_especial(int value);
    void setEscudo(int value);
    void setPos(pair <int,int> new_pos);

    void mover(char mov);
    void atacar(Nave *);

    void cargarImagen(QString path);
    void inicializarLayout(QWidget *parent);


};

#endif
