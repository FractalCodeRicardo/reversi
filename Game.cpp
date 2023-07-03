#include "Game.h"
#include "Tablero.h"
#include "Drawer.h"
#include "Cursor.h"
#include "Posicion.h"
#include "Jugador.h"
#include <iostream>
#include <list>

using namespace std;

Game::Game()
{
    seleccion = NULL;
    turno = Jugador::BLANCO;
}

Cursor &Game::getCursor()
{
    return cursor;
}

Tablero &Game::getTablero()
{
    return tablero;
}

void Game::setDrawer(Drawer *drawer)
{
    this->drawer = drawer;
    tablero.setDrawer(drawer);
}

void Game::pintarTablero()
{
    tablero.pintarCuadros();
}

void Game::pintarCursor()
{
    int x = cursor.getX();
    int y = cursor.getY();

    this->tablero.pintarCuadro(x, y, Drawer::YELLOW);
}

void Game::seleccionar(int x, int y)
{
    if (seleccion != NULL)
    {
        delete seleccion;
    }

    seleccion = new Posicion();
    seleccion->x = x;
    seleccion->y = y;
}

void Game::deseleccionar()
{
    delete seleccion;
    seleccion = NULL;
}

void Game::pintarSeleccion()
{
    if (seleccion == NULL)
        return;

    int x = seleccion->x;
    int y = seleccion->y;

    tablero.pintarCuadroSeleccion(x, y, Drawer::YELLOW);
}

Game::~Game()
{
    if (seleccion != NULL)
    {
        delete seleccion;
    }
}

int Game::realizarMovimiento()
{
    int x = cursor.getX();
    int y = cursor.getY();
    Jugador turno = this->turno;

    list<Posicion> arriba = obtenerLinea(x, y, 0, -1);
    list<Posicion> abajo = obtenerLinea(x, y, 0, 1);
    list<Posicion> izquierda = obtenerLinea(x, y, -1, 0);
    list<Posicion> derecha = obtenerLinea(x, y, 1, 0);
    list<Posicion> arribaIzquierda = obtenerLinea(x, y, -1, -1);
    list<Posicion> arribaDerecha = obtenerLinea(x, y, 1, -1);
    list<Posicion> abajoIzquierda = obtenerLinea(x, y, -1, 1);
    list<Posicion> abajoDerecha = obtenerLinea(x, y, 1, 1);

    list<Posicion> cambios;

    cambios.splice(cambios.end(), obtenerCambios(arriba, turno));
    cambios.splice(cambios.end(), obtenerCambios(abajo, turno));
    cambios.splice(cambios.end(), obtenerCambios(izquierda, turno));
    cambios.splice(cambios.end(), obtenerCambios(derecha, turno));

    cambios.splice(cambios.end(), obtenerCambios(arribaIzquierda, turno));
    cambios.splice(cambios.end(), obtenerCambios(arribaDerecha, turno));
    cambios.splice(cambios.end(), obtenerCambios(abajoIzquierda, turno));
    cambios.splice(cambios.end(), obtenerCambios(abajoDerecha, turno));

    list<Posicion>::iterator it;
    for (it = cambios.begin(); it != cambios.end(); ++it)
    {
        int x = it->x;
        int y = it->y;
        CuadroTablero &cuadro = tablero.cuadro(x, y);

        cuadro.cambiarcirculo();
    }

    if (cambios.size() > 0)
    {
        CuadroTablero &cuadro = tablero.cuadro(cursor.getX(), cursor.getY());
        cuadro.asignarcirculo((int)turno);
    }

    return cambios.size();
}

list<Posicion> Game::obtenerCambios(list<Posicion> &lista, Jugador turno)
{
    list<Posicion> cambios;
    list<Posicion>::iterator it;
    bool tieneDelMismoColor = false;
    for (it = lista.begin(); it != lista.end(); ++it)
    {
        int x = it->x;
        int y = it->y;

        CuadroTablero &cuadro = tablero.cuadro(x, y);

        if (cuadro.Oc() == 0)
            break;

        int turnoInt = (int)turno;
        if (cuadro.Oc() == turnoInt)
        {
            tieneDelMismoColor = true;
            break;
        }

        if (cuadro.Oc() != turnoInt)
        {
            Posicion pos;
            pos.x = x;
            pos.y = y;
            cambios.push_back(pos);
        }
    }

    if (!tieneDelMismoColor)
    {
        cambios.clear();
    }

    return cambios;
}

bool Game::fueraDelTablero(int x, int y)
{
    return x < 0 || y < 0 || x > 7 || y > 7;
}

list<Posicion> Game::obtenerLinea(int x, int y, int incrementoX, int incrementoY)
{
    list<Posicion> lista;

    x = x + incrementoX;
    y = y + incrementoY;

    while (!fueraDelTablero(x, y))
    {
        Posicion pos;
        pos.x = x;
        pos.y = y;
        lista.push_back(pos);

        x = x + incrementoX;
        y = y + incrementoY;
    }

    return lista;
}

void Game::cambiarTurno()
{
    if (turno == Jugador::NEGRO)
    {
        turno = Jugador::BLANCO;
    }
    else
    {
        turno = Jugador::NEGRO;
    }
}

void Game::pintarMarcador()
{
    int cantidadNegras = tablero.cantidadFichasNegras();
    int cantidadBlancas = tablero.cantidadFichasBlancas();

    drawer->text(100, 100, 11, "NEGRAS: ");
    drawer->text(100, 100, 11, "BLANCAS: ");
}