#include "CuadroTablero.h"
#include "Drawer.h"

CuadroTablero::CuadroTablero()
{
    cx = -1;
    cy = -1;
    circulo = 0;
}

void CuadroTablero::setDrawer(Drawer* drawer)
{
    this->drawer = drawer;
}

int CuadroTablero::Ocx()
{
    return cx;
}

int CuadroTablero::Ocy()
{
    return cy;
}

int CuadroTablero::Oc()
{
    return circulo;
}

int CuadroTablero::Cc(int g)
{
    circulo = g;
}

void CuadroTablero::cambiarcirculo()
{
    if (circulo == 1)
        circulo = 2;
    else
        circulo = 1;
}

void CuadroTablero::cambiarcoordenada(int x, int y)
{
    cx = x * 50;
    cy = y * 50;
}

void CuadroTablero::asignarcirculo(int c)
{ // si circulo=1 es blanco, si circulo=2 es negro, si circulo=0 no hay nada
    circulo = c;
}

void CuadroTablero::pintarcuadro(int color)
{
    this->drawer->setColor(color);
    this->drawer->rectangle(cx - 24, cy - 24, cx + 24, cy + 24);

    if (circulo == 1)
    {
        this->drawer->setColor(Drawer::GREEN);
        this->drawer->circle(cx, cy, 15);
    }

    if (circulo == 2)
    {
        this->drawer->setColor(Drawer::RED);
        this->drawer->circle(cx, cy, 15);
    }
}

void CuadroTablero::pintarCuadroSeleccion(int color)
{
    this->drawer->setColor(color);
    this->drawer->rectangle(cx - 20, cy - 20, cx + 20, cy + 20);
}