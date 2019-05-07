#include "caza.h"

Caza::Caza():
    Nave(Tipo_caza::salud, Tipo_caza::escudo,
         Tipo_caza::ataque, Tipo_caza::ataque_especial,
         Tipo::pos_defecto)
{
    this->imagenes[Mov::Up] = QPixmap(":/images/caza_U.png");
    this->imagenes[Mov::Down] = QPixmap(":/images/caza_D.png");
    this->imagenes[Mov::Left] = QPixmap(":/images/caza_L.png");
    this->imagenes[Mov::Right] = QPixmap(":/images/caza_R.png");
    this->key = Mov::Down;
}

void Caza::habilidad(bool value){
    if (value == true){
        this->setVelocidad(2);
    } else {
        this->setVelocidad(1);
    }
}
