#include "nave.h"
#include "gamewindow.h"

Nave::Nave()
{
    this->vida = 50;
    this->escudo = 20;
    this->ataque = 4;
    this->ataque_especial = 4;
    this->pos.first = 0;
    this->pos.second = 0;

    this->velocidad = 1;
    this->puntos_accion = PA_MAX;

    this->rango_ataque = 2;

}

Nave::Nave(int vid, int esc, int ataq, int ataq_es, pair<int, int> pos){
    this->vida = vid;
    this->escudo = esc;
    this->ataque = ataq;
    this->ataque_especial = ataq_es;
    if (pos.first >= 0 && pos.first < COLUMNAS){
        this->pos.first = pos.first;
    }else this->pos.first = 0;
    if (pos.second >= 0 && pos.second < FILAS){
        this->pos.second = pos.second;
    }else this->pos.second = 0;

    this->velocidad = 1;
    this->puntos_accion = PA_MAX;


}

Nave::Nave(Nave &n) {
    this->vida = n.vida;
    this->escudo = n.escudo;
    this->ataque = n.ataque;
    this->ataque_especial = n.ataque_especial;
    if (pos.first >= 0 && pos.first < COLUMNAS){
        this->pos.first = pos.first;
    }else this->pos.first = 0;
    if (pos.second >= 0 && pos.second < FILAS){
        this->pos.second = pos.second;
    }else this->pos.second = 0;

    this->velocidad = n.velocidad;
    this->puntos_accion = n.puntos_accion;

    this->key = n.key;
    this->imagenes = n.imagenes;
    this->puntos_accion = n.puntos_accion;
}

Nave::~Nave(){

}

// Metodos GET
Nave* Nave::getNave() { return this; }
int Nave::getVida() { return vida; }
int Nave::getAtaque() { return ataque; }
int Nave::getAtaque_especial() { return ataque_especial; }
int Nave::getEscudo() { return escudo; }
int Nave::getKey() { return this->key; }
int Nave::getX() { return this->pos.first; }
int Nave::getY() { return this->pos.second; }
int Nave::getPuntos_accion() { return this->puntos_accion; }
int Nave::getRango_ataque() { return this->rango_ataque; }
int Nave::getVelocidad() { return this->velocidad; }
pair<int,int> Nave::getPos() { return this->pos;  }
QPixmap Nave::getImagen() { return this->imagenes[this->key]; }
map<int, QPixmap> Nave::getImagenes() { return this->imagenes; }

// Metodos SET
void Nave::setVida(int value) {
    if ( value > 0 )
    {
        this->vida = value;
    } else this->vida = 0;
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

void Nave::setPos(pair<int, int> pos){
    if (pos.first >= 0 && pos.first < COLUMNAS){
        this->pos.first = pos.first;
    }else this->pos.first = 0;
    if (pos.second >= 0 && pos.second < FILAS){
        this->pos.second = pos.second;
    }else this->pos.second = 0;
}

void Nave::setPuntos_accion(int p) {
    if ( p >= 0 || p <= PA_MAX )
        this->puntos_accion = p;
}

void Nave::setRango_ataque(int rng) {
    if ( rng > 0 )
        this->rango_ataque = rng;
}

void Nave::setVelocidad(int v) {
    if ( v > 0 )
        this->velocidad = v;
}

bool Nave::mover(int mov){

    if ( this->puntos_accion > 0) {
        if (mov == Mov::Up && this->pos.second - this->velocidad >= 0) {
            this->pos.second -= this->velocidad;
        }else if (mov == Mov::Down && this->pos.second + this->velocidad < FILAS){
            this->pos.second += this->velocidad;
        }else if (mov == Mov::Right && this->pos.first + this->velocidad < COLUMNAS) {
            this->pos.first += this->velocidad;
        }else if (mov == Mov::Left && this->pos.first - this->velocidad >= 0) {
            this->pos.first -= this->velocidad;;
        }
        this->key = mov;
    }else return false;

    this->puntos_accion--;
    return true;

}

void Nave::atacar(Nave *nave_enemiga)
{
    // Mensaje de informacion al usuario
  /*  QMessageBox msg;
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setDefaultButton(QMessageBox::Ok);
    msg.setWindowTitle("Informe de situación");
    msg.setFont(QFont("Small Fonts",12,QFont::Bold));
    msg.setStyleSheet("QPushButton{ background-color: rgba(72, 73, 88, 255);"
                      " border-style: outset;"
                      "border-width: 2px;"
                      " border-radius: 2px;"
                      "border-color: rgb(137, 139, 142);"
                      "padding: 6px;"
                      "color: rgb(220, 220, 220);}\n"
                      "QMessageBox{ background-color: rgb(36, 49, 63);"
                      " border-style: outset;"
                      "border-width: 2px;"
                      "border-radius: 2px;"
                      "border-color: black;"
                      "color: white}");*/


    if ( abs(this->pos.first - nave_enemiga->pos.first) + abs(this->pos.second - nave_enemiga->pos.second) <= this->rango_ataque )
    {
        qDebug("Ataque solicitado");
        nave_enemiga->setVida(nave_enemiga->getVida() - this->ataque*(1 - nave_enemiga->getEscudo()/100));
       // msg.setInformativeText("Enemigo alcanzado.\n ¡Buen trabajo capitán!");
        qDebug(QString::number(this->rango_ataque).toLatin1());

        this->puntos_accion--;
    } else {
        //msg.setText("Enemigo fuera de alcance.");
    }
  //  msg.exec();

   /* if (nave_enemiga->getVida() == 0){
      //  msg.close();
        // Mensaje de informacion al usuario
      /*  QMessageBox msg;
        msg.setText("¡Enemigo neutralizado!");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);
        msg.setWindowTitle("Informe de situación");
        msg.setFont(QFont("Small Fonts",12,QFont::Bold));
        msg.setStyleSheet("QPushButton{ background-color: rgba(72, 73, 88, 255);"
                          " border-style: outset;"
                          "border-width: 2px;"
                          " border-radius: 2px;"
                          "border-color: rgb(137, 139, 142);"
                          "font: bold 14px;"
                          "padding: 6px;"
                          "color: rgb(220, 220, 220);}\n"
                          "QMessageBox{ background-color: rgb(36, 49, 63);"
                          " border-style: outset;"
                          "border-width: 2px;"
                          "border-radius: 2px;"
                          "border-color: black;"
                          "text-color: white}");
        msg.exec();
    }
    msg.close();*/

}
