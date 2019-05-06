#ifndef ENEMIGOACORAZADO_H
#define ENEMIGOACORAZADO_H

#include "acorazado.h"
#include "enemigo.h"

class EnemigoAcorazado: public Enemigo, public Acorazado
{
public:
    EnemigoAcorazado();
};

#endif // ENEMIGOACORAZADO_H
