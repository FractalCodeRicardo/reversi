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
    rect.y = y1;
    rect.w = x2 - x1;
    rect.h = y2 - y1;

    SDL_RenderDrawRect(renderer, &rect);
}

void Drawer::circle(int centreX, int centreY, int radius)
{
    int diameter = (radius * 2);

    int x = (radius - 1);
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = (tx - diameter);

    while (x >= y)
    {
        // Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void Drawer::setColor(int color)
{
    if (color == Drawer::WHITE)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        return;
    }

    if (color == Drawer::GRAY)
    {
        SDL_SetRenderDrawColor(renderer, 160, 160, 160, 0);
        return;
    }

    if (color == Drawer::BLACK)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        return;
    }

    if (color == Drawer::GREEN)
    {
        SDL_SetRenderDrawColor(renderer, 0, 200, 14, 0);
        return;
    }

    if (color == Drawer::RED)
    {
        SDL_SetRenderDrawColor(renderer, 200, 0, 111, 0);
        return;
    }

    if (color == Drawer::YELLOW)
    {
        SDL_SetRenderDrawColor(renderer, 204, 223, 0, 0);
        return;
    }
}
