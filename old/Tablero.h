#ifndef TABLERO_H
#define TABLERO_H

#include "Square.h"
#include "Drawer.h"

class Tablero
{
private:
    Square cuadros[8][8];
    Drawer *drawer;
    void setDrawerCuadros();

public:
    Tablero();
    void setDrawer(Drawer *drawer);
    void pintarCuadros();
    void pintarCuadro(int x, int y, int color);
    void pintarCuadroSeleccion(int x, int y, int color);
    int cantidadFichasNegras();
    int cantidadFichasBlancas();
    int cantidadFichas(int jugador);
    Square &cuadro(int x, int y);
};

#endif