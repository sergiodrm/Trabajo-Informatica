#ifndef CAZA_H
#define CAZA_H

#include "nave.h"


class Caza : virtual public Nave
{
public:
    Caza();
    void habilidad(bool value);
};

#endif // CAZA_H
