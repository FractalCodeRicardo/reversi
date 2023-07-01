#include "Tablero.h"
#include "Drawer.h"

Tablero::Tablero()
{
    cuadros[3][3].asignarcirculo(1); // poniendo las primeras fichas en el tablero
    cuadros[3][4].asignarcirculo(2);
    cuadros[4][3].asignarcirculo(2);
    cuadros[4][4].asignarcirculo(1);
}

void Tablero::setDrawer(Drawer *drawer)
{
    this->drawer = drawer;
    this->setDrawerCuadros();
}

void Tablero::setDrawerCuadros()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cuadros[i][j].setDrawer(this->drawer);
}

void Tablero::pintarCuadros()
{
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            pintarCuadro(x, y, Drawer::GRAY);
        }
    }
}

void Tablero::pintarCuadro(int x, int y, int color) {
    CuadroTablero cuadro = cuadros[y][x];
    cuadro.cambiarcoordenada(y + 1, x + 1);
    cuadro.pintarcuadro(color);     
}


void Tablero::pintarCuadroSeleccion(int x, int y, int color) {
    CuadroTablero cuadro = cuadros[y][x];
    cuadro.cambiarcoordenada(y + 1, x + 1);
    cuadro.pintarCuadroSeleccion(color);     
}
