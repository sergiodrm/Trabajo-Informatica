#include "destructor.h"

Destructor::Destructor():
    Nave(Tipo_destructor::salud, Tipo_destructor::escudo,
         Tipo_destructor::ataque, Tipo_destructor::ataque_especial,
                               Tipo::pos_defecto)
{
    this->imagenes[Mov::Up] = QPixmap(":/images/destructor_U.png");
    this->imagenes[Mov::Down] = QPixmap(":/images/destructor_D.png");
    this->imagenes[Mov::Left] = QPixmap(":/images/destructor_L.png");
    this->imagenes[Mov::Right] = QPixmap(":/images/destructor_R.png");
    this->key = Mov::Down;

}

void Destructor::habilidad(bool value) {
    int temp = this->getAtaque_especial();
    if (value == true){
        this->setAtaque_especial(floor(this->getAtaque_especial()*1.25));
    } else {
         this->setAtaque_especial(temp);
    }

}
