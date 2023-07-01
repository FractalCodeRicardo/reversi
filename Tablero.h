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
    void pintarCuadro(int x, int y, int color);
    void pintarCuadroSeleccion(int x, int y, int color);
};

#endif