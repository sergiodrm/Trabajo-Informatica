#ifndef WARSHIP_H
#define WARSHIP_H

#include "nave.h"


class Warship : virtual public Nave
{
public:
    Warship();
    void habilidad(bool value);
};

#endif // WARSHIP_H
