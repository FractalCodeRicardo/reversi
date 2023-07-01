#ifndef TABLERO_H
#define TABLERO_H

#include "CuadroTablero.h"
#include "Drawer.h"

class Tablero
{
private:
    CuadroTablero cuadros[8][8];
    Drawer *drawer;
    void setDrawerCuadros();

public:
    Tablero();
    void setDrawer(Drawer *drawer);
    void pintarCuadros();
};

#endif