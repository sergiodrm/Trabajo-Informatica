#include "enemigocaza.h"

EnemigoCaza::EnemigoCaza(): Enemigo(), Caza(),
    Nave(Tipo_caza::salud, Tipo_caza::escudo,
         Tipo_caza::ataque, Tipo_caza::ataque_especial,
         Tipo::pos_defecto)
{

    this->imagenes[Mov::Up] = QPixmap(":/images/caza_enemy_U.png");
    this->imagenes[Mov::Down] = QPixmap(":/images/caza_enemy_D.png");
    this->imagenes[Mov::Left] = QPixmap(":/images/caza_enemy_L.png");
    this->imagenes[Mov::Right] = QPixmap(":/images/caza_enemy_R.png");
    this->key = Mov::Down;
    this->id = 1;
}
