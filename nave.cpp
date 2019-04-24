#include "nave.h"

Nave::nave()
{
    vida = 50;
    escudo = 20;
    ataque = 4;
    ataque_especial = 4;
    pos.first = 0;
    pos.second = 0;

}

Nave::Nave(int vid, int esc, int ataq, int ataq_es, pair<int, int> pos ){

    vida = vid;
    escudo = esc;
    ataque = ataq;
    ataque_especial = ataq_es;
    this->pos.first = pos.first;
    this->pos.second = pos.second;
}

// Metodos GET
int Nave::getVida(){
    return vida;
}

int Nave::getAtaque(){
    return ataque;
}

int Nave::getAtaque_especial(){
    return ataque_especial;
}

int Nave::getEscudo(){
    return escudo;
}

pair <int,int> getPos(){
    return std::make_pair(pos.first, pos.second);
}

// Metodos SET
void Nave::setVida(int value){
    this->vida = value;
}

void Nave::setAtaque(int value){
    this->ataque = value;
}

void Nave::setAtaque_especial(int value){
    this->ataque_especial = value;
}

void Nave::setEscudo(int value){
    this->escudo = value;
}

void Nave::setPos(pair<int, int> value){
    this->pos = make_pair(value.first,value.second);
}

void Nave::mover(char mov){

    //Según el string, se modifica la posición de la nave en una de las 4 posibles direcciones

    if (mov == "w" || mov == "W"); this->pos.second++;
    if ((mov == "s" || mov == "S")); this->pos.second--;
    if ((mov == "d" || mov == "D")); this->pos.first++;
    if (mov == "a" || mov == "A"); this->pos.second--;

}
