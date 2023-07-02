#ifndef CUADRO_TABLERO_H
#define CUADRO_TABLERO_H

#include "Drawer.h"

class CuadroTablero
{
    
private:
    int cx;
    int cy;
    int circulo;
    Drawer* drawer;

public:
    CuadroTablero();
    void setDrawer(Drawer* drawer);
    void pintarcuadro(int);
    void pintarCuadroSeleccion(int);
    int Ocx();
    int Ocy();
    int Oc();
    int Cc(int g);
    void cambiarcirculo();
    void cambiarcoordenada(int x, int y);
    void asignarcirculo(int c);
};

#endif
