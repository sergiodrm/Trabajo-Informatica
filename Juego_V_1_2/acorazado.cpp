#include "acorazado.h"

Acorazado::Acorazado():
    Nave(Tipo_acorazado::salud, Tipo_acorazado::escudo,
         Tipo_acorazado::ataque, Tipo_acorazado::ataque_especial,
         Tipo::pos_defecto)
{
    this->imagenes[Mov::Up] = QPixmap(":/images/acorazado_U.png");
    this->imagenes[Mov::Down] = QPixmap(":/images/acorazado_D.png");
    this->imagenes[Mov::Left] = QPixmap(":/images/acorazado_L.png");
    this->imagenes[Mov::Right] = QPixmap(":/images/acorazado_R.png");
    this->key = Mov::Down;
}

void Acorazado::habilidad(bool value) {
    int temp = this->getEscudo();
    if (value == true){
        this->setEscudo(floor(this->getEscudo()*1.25));
    } else {
         this->setEscudo(60);
    }
}
