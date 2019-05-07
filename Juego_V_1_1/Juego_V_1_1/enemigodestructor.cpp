#include "enemigodestructor.h"

EnemigoDestructor::EnemigoDestructor(): Enemigo(), Destructor(),
    Nave(Tipo_destructor::salud, Tipo_destructor::escudo,
         Tipo_destructor::ataque, Tipo_destructor::ataque_especial,
                               Tipo::pos_defecto)
{

    this->imagenes[Mov::Up] = QPixmap(":/images/destructor_enemy_U.png");
    this->imagenes[Mov::Down] = QPixmap(":/images/destructor_enemy_D.png");
    this->imagenes[Mov::Left] = QPixmap(":/images/destructor_enemy_L.png");
    this->imagenes[Mov::Right] = QPixmap(":/images/destructor_enemy_R.png");
    this->key = Mov::Down;
    this->id = 2;
}
