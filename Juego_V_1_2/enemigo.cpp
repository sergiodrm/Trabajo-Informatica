#include "enemigo.h"

Enemigo::Enemigo(): Nave()
{
    this->rango_vision = 3;
}

void Enemigo::mover(Nave *jugador, vector<pair<int, int>> pos_bloq, vector<pair<int, int>> pos_en) {
    pair<int, int> pos_j = jugador->getPos();
    pair<int, int> avance = this->pos;



    if ( floor(sqrt(abs(avance.first - pos_j.first)^2 - abs(avance.second - pos_j.second)^2)) <= this->rango_vision)
    {
        if (floor(sqrt(abs(avance.first - pos_j.first)^2 - abs(avance.second - pos_j.second)^2)) >= this->rango_ataque)
        {
            if ( abs(avance.first - pos_j.first) < abs(avance.second - pos_j.second) )
            {
                if ( avance.first -pos_j.first > 0 &&
                     avance.first + this->velocidad < COLUMNAS )
                {
                    avance.first += this->velocidad;
                    this->key = Mov::Right;
                }else if ( avance.first -pos_j.first < 0 &&
                           avance.first - this->velocidad >= 0 )
                {
                    avance.first -= this->velocidad;
                    this->key = Mov::Left;
                }
            }else
            {
                if ( avance.second -pos_j.second > 0 &&
                     avance.second + this->velocidad < FILAS )
                {
                    avance.second += this->velocidad;
                    this->key = Mov::Down;
                }else if ( avance.second -pos_j.second < 0 &&
                           avance.second - this->velocidad >= 0 )
                {
                    avance.second -= this->velocidad;
                    this->key = Mov::Up;
                }
            }
        } else {
            this->atacar(jugador);
        }
    }
    /* Comprobacion del avance */

    bool pos_valida;
    do {

        pos_valida = true;
        vector<pair<int, int>>::iterator item;
        if (avance.first >= 0 && avance.first < COLUMNAS &&
                avance.second >= 0 && avance.second < FILAS )
        {
            for ( item = pos_bloq.begin(); item != pos_bloq.end(); item++ )
            {
                if (item->first == avance.first && item->second == avance.second)
                    pos_valida = false;
            }
            if ( pos_valida )
            {
                for ( item = pos_en.begin(); item != pos_en.end(); item++ )
                {
                    if (item->first == avance.first && item->second == avance.second)
                        pos_valida = false;
                }
                if (avance.first == pos_j.first && avance.second == pos_j.second)
                    pos_valida = false;
            }
        } else pos_valida = false;

        if (!pos_valida)
        {
            avance = this->pos;
            int mov = rand() % 4;
            this->key = mov;
            switch ( mov )
            {
            case Mov::Up:
                if (avance.second - this->velocidad >= 0)
                    avance.second -= this->velocidad;
                break;
            case Mov::Down:
                if (avance.second + this->velocidad < FILAS)
                    avance.second += this->velocidad;
                break;
            case Mov::Right:
                if (avance.first + this->velocidad < COLUMNAS)
                    avance.first += this->velocidad;
                break;
            case Mov::Left:
                if (avance.first - this->velocidad >= 0)
                    avance.first -= this->velocidad;
                break;
            }
        }
    } while( !pos_valida );

    this->pos.first = avance.first;
    this->pos.second = avance.second;
}

int Enemigo::getRango_vision() { return this->rango_vision; }
void Enemigo::setRango_vision(int r) { this->rango_vision = r; }
int Enemigo::getId() { return this->id; }
void Enemigo::setId(int id) { this->id = id; }
