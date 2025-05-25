#ifndef DRAWER_H
#define DRAWER_H

#include "SDL2/SDL.h"
#include <string>

using namespace std;

class Drawer
{
public:

    const static int WHITE = 0;
    const static int GRAY = 1;
    const static int BLACK = 3;
    const static int GREEN = 4;
    const static int RED = 5;
    const static int YELLOW = 6;
    
    void rectangle(int x1, int y1, int x2, int y2);
    void circle(int x, int y, int radius);
    void setRenderer(SDL_Renderer* renderer);
    void setColor(int color);
    void text(int x, int y, int size, char* text);

private:
    SDL_Renderer *renderer;
};

#endif