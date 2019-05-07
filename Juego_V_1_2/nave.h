#ifndef NAVE_H
#define NAVE_H

#include <string.h>
#include <QPixmap>
#include <QLabel>
#include <QDir>

#include <iostream>

#define PA_MAX 2


using namespace std;

namespace Mov{
enum{
    Up, Down,
    Left, Right
};
}

namespace Tipo {
enum {
    tipo_caza, tipo_acorazado,
    tipo_destructor, tipo_warship
};
const pair<int, int> pos_defecto = make_pair(0, 0);
}

namespace Tipo_caza {
    const int salud = 100;
    const int escudo = 20;
    const int ataque = 60;
    const int ataque_especial = 20;
}

namespace Tipo_acorazado {
    const int salud = 100;
    const int escudo = 60;
    const int ataque = 10;
    const int ataque_especial = 40;

}

namespace Tipo_destructor {
    const int salud = 100;
    const int escudo = 30;
    const int ataque = 30;
    const int ataque_especial = 60;
}

namespace Tipo_warship {
    const int salud = 100;
    const int escudo = 40;
    const int ataque = 50;
    const int ataque_especial = 50;
}

class Nave{

public:
    Nave();
    Nave(int vida, int esc, int ataq, int ataq_es, pair<int, int> pos);
    Nave(Nave &n);
    ~Nave();

    Nave* getNave();

    int getVida();
    int getAtaque();
    int getAtaque_especial();
    int getEscudo();
    int getX();
    int getY();
    int getPuntos_accion();
    int getKey();
    int getRango_ataque();
    int getVelocidad();
    pair <int,int> getPos();
    map<int, QPixmap> getImagenes();
    QPixmap getImagen();



    void setVida(int value);
    void setAtaque(int value);
    void setAtaque_especial(int value);
    void setEscudo(int value);
    void setPos(pair <int,int> pos);
    void setKey(int key);
    void setPuntos_accion(int p);
    void setRango_ataque(int rng);
    void setVelocidad(int v);

    bool mover(int mov);
    bool atacar(Nave *nave_enemiga);
    bool atacarEsp(Nave *nave_enemiga);

protected:
    int key;
    map<int, QPixmap> imagenes;
    int vida;
    int escudo;
    int ataque;
    int ataque_especial;
    pair <int, int> pos;
    int puntos_accion;
    int velocidad;
    int rango_ataque;
};

#endif
