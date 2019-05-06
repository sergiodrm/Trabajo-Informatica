#ifndef ENEMIGOWARSHIP_H
#define ENEMIGOWARSHIP_H

#include "enemigo.h"
#include "warship.h"

class EnemigoWarship: public Enemigo, public Warship
{
public:
    EnemigoWarship();
};

#endif // ENEMIGOWARSHIP_H
