#ifndef ACORAZADO_H
#define ACORAZADO_H

#include "nave.h"


class Acorazado : virtual public Nave
{
public:
    Acorazado();
    void habilidad(bool value);
};

#endif // ACORAZADO_H
