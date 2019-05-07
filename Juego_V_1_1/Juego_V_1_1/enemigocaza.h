#ifndef ENEMIGOCAZA_H
#define ENEMIGOCAZA_H

#include "enemigo.h"
#include "caza.h"

class EnemigoCaza: public Enemigo, public Caza
{
public:
    EnemigoCaza();
};

#endif // ENEMIGOCAZA_H
