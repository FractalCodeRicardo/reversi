#include "Cursor.h"

void Cursor::abajo()
{
    if (y == 7)
        y = 0;
    else
        y++;
}

void Cursor::arriba()
{
    if (y == 0)
        y = 7;
    else
        y--;
}

void Cursor::derecha()
{
    if (x == 7)
        x = 0;
    else
        x++;
}

void Cursor::izquierda()
{
    if (x == 0)
        x = 7;
    else
        x--;
}

int Cursor::getX()
{
    return x;
}

int Cursor::getY()
{
    return y;
}
