#ifndef CUADRO_TABLERO_H
#define CUADRO_TABLERO_H

#include "Drawer.h"

class Square
{
    
private:
    int cx;
    int cy;
    int circulo;
    Drawer* drawer;

public:
    Square();
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
