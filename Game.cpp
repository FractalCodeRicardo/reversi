#include "Game.h"
#include "Tablero.h"
#include "Drawer.h"
#include "Cursor.h"
#include "Posicion.h"

Game::Game()
{
    tablero = new Tablero();
    cursor = new Cursor();
    seleccion = NULL;
}

Cursor *Game::getCursor()
{
    return cursor;
}

Tablero *Game::getTablero()
{
    return tablero;
}

void Game::setDrawer(Drawer *drawer)
{
    this->drawer = drawer;
    this->tablero->setDrawer(drawer);
}

void Game::pintarTablero()
{
    this->tablero->pintarCuadros();
}

void Game::pintarCursor()
{
    int x = cursor->getX();
    int y = cursor->getY();

    this->tablero->pintarCuadro(x, y, Drawer::YELLOW);
}

void Game::seleccionar(int x, int y)
{
    seleccion = new Posicion();
    seleccion->x = x;
    seleccion->y = y;
}

void Game::deseleccionar()
{
    seleccion = NULL;
}

void Game::pintarSeleccion()
{
    if (seleccion == NULL)
        return;

    int x = seleccion->x;
    int y = seleccion->y;
    
    this->tablero->pintarCuadroSeleccion(x, y, Drawer::YELLOW);
}
