#include "nave.h"

Nave::Nave()
{
    vida = 50;
    escudo = 20;
    ataque = 4;
    ataque_especial = 4;
    pos.first = 0;
    pos.second = 0;
}

Nave::Nave(int vid, int esc, int ataq, int ataq_es, pair<int, int> pos, QString path_image ){

    vida = vid;
    escudo = esc;
    ataque = ataq;
    ataque_especial = ataq_es;
    this->pos.first = pos.first;
    this->pos.second = pos.second;
    this->imagen.load(path_image);
}

Nave::~Nave(){
}

// Metodos GET
int Nave::getVida() { return vida; }
int Nave::getAtaque() { return ataque; }
int Nave::getAtaque_especial() { return ataque_especial; }
int Nave::getEscudo() { return escudo; }
pair <int,int> getPos() { /*return*/  }
QPixmap Nave::getImagen() { return this->imagen; }

// Metodos SET
void Nave::setVida(int value) {
    if ( value > 0 )
        this->vida = value;
}

void Nave::setAtaque(int value){
    if ( value > 0 )
        this->ataque = value;
}

void Nave::setAtaque_especial(int value){
    if ( value > 0 )
        this->ataque_especial = value;
}

void Nave::setEscudo(int value){
    if ( value > 0 )
        this->escudo = value;
}

void Nave::setPos(pair<int, int> value){
    if ( value.first >= 0 && value.second >= 0)
    this->pos = make_pair(value.first,value.second);
}

int Nave::setDanno(Nave *mi_nave, bool tipo_ataque){
    int puntos_danno = 0;
    if (tipo_ataque == 0){ // Daño causado por ataque
        puntos_danno = mi_nave->ataque * (1-mi_nave->escudo);
    } else {    // Daño causado por ataque especial
        puntos_danno = mi_nave->ataque_especial * (1-mi_nave->escudo);
    }
    return puntos_danno;
}

void Nave::mover(char mov){
    //Según el char, se modifica la posición de la nave en una de las 4 posibles direcciones
    if (mov == 'w' || mov == 'W') this->pos.second++;
    if ((mov == 's' || mov == 'S')) this->pos.second--;
    if ((mov == 'd' || mov == 'D')) this->pos.first++;
    if (mov == 'a' || mov == 'A') this->pos.second--;
}


void Nave::atacar(Nave *nave_enemiga){
    nave_enemiga->setVida(nave_enemiga->getVida()-this->ataque);
}

