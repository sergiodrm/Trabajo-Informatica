#include "enemigoacorazado.h"

EnemigoAcorazado::EnemigoAcorazado(): Enemigo(), Acorazado(),
    Nave(Tipo_acorazado::salud, Tipo_acorazado::escudo,
         Tipo_acorazado::ataque, Tipo_acorazado::ataque_especial,
         Tipo::pos_defecto)
{
    this->imagenes[Mov::Up] = QPixmap(":/images/acorazado_enemy_U.png");
    this->imagenes[Mov::Down] = QPixmap(":/images/acorazado_enemy_D.png");
    this->imagenes[Mov::Left] = QPixmap(":/images/acorazado_enemy_L.png");
    this->imagenes[Mov::Right] = QPixmap(":/images/acorazado_enemy_R.png");
    this->key = Mov::Down;
    this->id = 0;
}
