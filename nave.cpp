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

Nave::Nave(int vid, int esc, int ataq, int ataq_es, pair<int, int> pos, QString path_image, QWidget* parent){
    vida = vid;
    escudo = esc;
    ataque = ataq;
    ataque_especial = ataq_es;
    this->pos.first = pos.first;
    this->pos.second = pos.second;
    this->imagen.load(path_image);
    this->layout.setParent(parent);
    this->layout.setPixmap(this->imagen);
    this->layout.setGeometry(this->getX(), this->getY(), this->imagen.width(), this->imagen.height());
}

Nave::Nave(QWidget *parent, QString path, int vida, int escudo, int ataque, int ataque_especial, pair<int, int> pos) {
    this->layout.setParent(parent);
    this->imagen.load(path);

    this->layout.setPixmap(this->imagen);
    this->layout.setGeometry(this->getX(), this->getY(), this->imagen.width(), this->imagen.height());

    this->vida = vida;
    this->escudo = escudo;
    this->ataque = ataque;
    this->ataque_especial = ataque_especial;
    this->pos = pos;
}

Nave::Nave(Nave &n) {
    this->vida = n.vida;
    this->escudo = n.escudo;
    this->ataque = n.ataque;
    this->ataque_especial = n.ataque_especial;
    this->pos.first = n.pos.first;
    this->pos.second = n.pos.second;
    this->imagen = n.imagen;
    this->layout.setParent(n.layout.parentWidget());
    this->layout.setPixmap(n.imagen);
    this->layout.setGeometry(n.layout.geometry());
}

Nave::~Nave(){

}

// Metodos GET
int Nave::getVida() { return vida; }
int Nave::getAtaque() { return ataque; }
int Nave::getAtaque_especial() { return ataque_especial; }
int Nave::getEscudo() { return escudo; }
pair<int,int> Nave::getPos() { return this->pos;  }
QPixmap Nave::getImagen() { return this->imagen; }
//QLabel Nave::getLayout() { return this->layout; }
int Nave::getX() { return this->pos.first; }
int Nave::getY() { return this->pos.second; }

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

void Nave::mover(char mov){
    //Según el char, se modifica la posición de la nave en una de las 4 posibles direcciones
    if (mov == 'w' || mov == 'W') this->pos.second--;
    if ((mov == 's' || mov == 'S')) this->pos.second++;
    if ((mov == 'd' || mov == 'D')) this->pos.first++;
    if (mov == 'a' || mov == 'A') this->pos.second--;

    this->layout.setGeometry(this->getX(), this->getY(), this->imagen.width(), this->imagen.height());
}

void Nave::cargarImagen(QString path) {
    this->imagen.load(path);
}

void Nave::inicializarLayout(QWidget *parent) {
    this->layout.setParent(parent);

    if (!this->imagen.isNull()) {
        this->layout.setPixmap(this->imagen);
        this->layout.setGeometry(this->getX(), this->getY(), this->imagen.width(), this->imagen.height());
    }
}

