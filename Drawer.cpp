#include "Drawer.h"
#include "SDL2/SDL.h"


void Drawer::setRenderer(SDL_Renderer *renderer) 
{
    this->renderer = renderer;
}

void Drawer::rectangle(int x1, int y1, int x2, int y2)
{
    SDL_Rect rect;
    rect.x = x1;
    rect.y = y2;
    rect.w = x2 - x1;
    rect.h = y2 - y1;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

}

void Drawer::circle(int x, int y, int radius)
{
    //TODO: search for function to draw circle
    int offset = radius - 2;
    SDL_Rect rect;

    int x1 = x - offset;    
    int y1 = y - offset;

    rect.x = x1;
    rect.y = y1;

    int x2 = x + offset;    
    int y2 = y + offset;

    rect.w = x1 - x2;
    rect.h = y1 - y2;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}