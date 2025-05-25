#ifndef CURSOR_H
#define CURSOR_H

class Cursor
{
private:
    int x;
    int y;

public:
    int getX();
    int getY();
    void derecha();
    void izquierda();
    void arriba();
    void abajo();
};

#endif