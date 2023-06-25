#ifndef DRAWER_H
#define DRAWER_H

#include "SDL2/SDL.h"

class Drawer
{
public:
    void rectangle(int x1, int y1, int x2, int y2);
    void circle(int x, int y, int radius);
    void setRenderer(SDL_Renderer *renderer);

private:
    SDL_Renderer *renderer;
};

#endif