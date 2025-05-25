#ifndef GAME_H
#define GAME_H

#include "Tablero.h"
#include "Cursor.h"
#include "Drawer.h"
#include "Posicion.h"
#include "Player.h"
#include <list>

using namespace std;

class Game {
    private:

    Tablero tablero;
    Cursor  cursor;
    Drawer* drawer;
    Posicion *seleccion;

    Player turno;
    
    public:
    Game();
    ~Game();
    Tablero& getTablero();
    Cursor& getCursor();
    void setDrawer(Drawer* drawer);
    void pintarTablero();
    void pintarCursor();
    void pintarSeleccion();
    void seleccionar(int x, int y);
    void deseleccionar();
    int realizarMovimiento();
    list<Posicion> obtenerCambios(list<Posicion>& lista, Player turno);
    bool fueraDelTablero(int x, int y);
    list<Posicion> obtenerLinea(int x, int y, int ix, int iy);
    void cambiarTurno();
    void pintarMarcador();
};

#endif
