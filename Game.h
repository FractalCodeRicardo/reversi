#ifndef GAME_H
#define GAME_H

#include "Tablero.h"
#include "Cursor.h"
#include "Drawer.h"
#include "Posicion.h"

class Game {
    private:

    Tablero *tablero;
    Cursor *cursor;
    Drawer *drawer;

    Posicion *seleccion;
    
    public:
    Game();
    Tablero* getTablero();
    Cursor* getCursor();
    void setDrawer(Drawer *drawer);
    void pintarTablero();
    void pintarCursor();
    void pintarSeleccion();
    void seleccionar(int x, int y);
    void deseleccionar();

};

#endif