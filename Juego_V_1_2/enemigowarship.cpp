#include "enemigowarship.h"

EnemigoWarship::EnemigoWarship(): Enemigo(), Warship(),
    Nave(Tipo_warship::salud, Tipo_warship::escudo,
         Tipo_warship::ataque, Tipo_warship::ataque_especial,
         Tipo::pos_defecto)
{
    this->imagenes[Mov::Up] = QPixmap(":/images/warship_enemy_U.png");
    this->imagenes[Mov::Down] = QPixmap(":/images/warship_enemy_D.png");
    this->imagenes[Mov::Left] = QPixmap(":/images/warship_enemy_L.png");
    this->imagenes[Mov::Right] = QPixmap(":/images/warship_enemy_R.png");
    this->key = Mov::Down;
    this->id = 3;
}
