#include "cuadrotablero.h"
#include "Drawer.h"

cuadrotablero::cuadrotablero()
{
    cx = -1;
    cy = -1;
    circulo = 0;
}

cuadrotablero::setDrawer(Drawer *drawer)
{
    this->drawer = drawer;
}

int cuadrotablero::Ocx()
{
    return cx;
}

int cuadrotablero::Ocy()
{
    return cy;
}

int cuadrotablero::Oc()
{
    return circulo;
}

void cuadrotablero::Cc(int g)
{
    circulo = g;
}

void cuadrotablero::cambiarcirculo()
{
    if (circulo == 1)
        circulo = 2;
    else
        circulo = 1;
}

void cuadrotablero::cambiarcoordenada(int y, int x)
{
    cx = x * 50;
    cy = y * 50;
}

void cuadrotablero::asignarcirculo(int c)
{ // si circulo=1 es blanco, si circulo=2 es negro, si circulo=0 no hay nada
    circulo = c;
}

void cuadrotablero::pintarcuadro(int color)
{
    //setcolor(color);
    this->drawer->rectangle(cx - 24, cy - 24, cx + 24, cy + 24);

    if (circulo == 1)
    {
        //setcolor(WHITE);
        //setfillstyle(SOLID_FILL, LIGHTGRAY);
        this->drawer->circle(cx, cy, 15);
        //floodfill(cx, cy, getmaxcolor());
    }

    if (circulo == 2)
    {
        //setcolor(WHITE);
        //setfillstyle(SOLID_FILL, DARKGRAY);
        this->drawer->circle(cx, cy, 15);
       // floodfill(cx, cy, getmaxcolor());
    }
}