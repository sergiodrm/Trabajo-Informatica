#include "warship.h"

Warship::Warship():
    Nave(Tipo_warship::salud, Tipo_warship::escudo,
         Tipo_warship::ataque, Tipo_warship::ataque_especial,
         Tipo::pos_defecto)
{

    this->imagenes[Mov::Up] = QPixmap(":/images/warship_U.png");
    this->imagenes[Mov::Down] = QPixmap(":/images/warship_D.png");
    this->imagenes[Mov::Left] = QPixmap(":/images/warship_L.png");
    this->imagenes[Mov::Right] = QPixmap(":/images/warship_R.png");
    this->key = Mov::Down;

}

void Warship::habilidad(bool value) {
    if (value == true){
        this->setAtaque(floor(this->getAtaque()*1.25));
    } else {
         this->setAtaque(floor(this->getAtaque()/1.25));
    }
}
