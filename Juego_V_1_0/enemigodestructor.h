#ifndef ENEMIGODESTRUCTOR_H
#define ENEMIGODESTRUCTOR_H

#include "enemigo.h"
#include "destructor.h"

class EnemigoDestructor: public Enemigo, public Destructor
{
public:
    EnemigoDestructor();
};

#endif // ENEMIGODESTRUCTOR_H
