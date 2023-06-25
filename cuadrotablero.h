#ifndef CUADRO_TABLERO_H
#define CUADRO_TABLERO_H

#include "Drawer.h"

class cuadrotablero
{
    
private:
    int cx;
    int cy;
    int circulo;
    Drawer *drawer;

public:
    cuadrotablero();
    void setDrawer(Drawer *drawer);
    void pintarcuadro(int);
    int Ocx();
    int Ocy();
    int Oc();
    int Cc(int g);
    void cambiarcirculo();
    void cambiarcoordenada();
    void asignarcirculo(int c);
};