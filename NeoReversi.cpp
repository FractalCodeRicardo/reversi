/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

// Using SDL and standard IO
#include "SDL2/SDL.h"
#include <stdio.h>
#include <iostream>
#include "Drawer.h"
#include "Tablero.h"
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

bool initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL is not initialized." << SDL_GetError();
		return false;
	}

	return true;
}

SDL_Window *createWindow()
{
	SDL_Window *window = SDL_CreateWindow("Reversi",
										  SDL_WINDOWPOS_UNDEFINED,
										  SDL_WINDOWPOS_UNDEFINED,
										  SCREEN_WIDTH, SCREEN_HEIGHT,
										  SDL_WINDOW_SHOWN);

	if (!window)
	{
		cout << "Error while creating " << SDL_GetError();
	}

	return window;
}

SDL_Renderer *createRenderer(SDL_Window *window)
{
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		std::cout << "Renderer could not be created!" << std::endl;
	}

	return renderer;
}

void drawLoop(Tablero *tablero, Drawer *drawer, SDL_Renderer *renderer)
{
	SDL_Event event;

	while (true)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
		{
			break;
		}

		SDL_RenderClear(renderer);

		drawer->setColor(Drawer::WHITE);
		tablero->pintarCuadros();
		//drawer->setColor(Drawer::WHITE);

		//drawer->rectangle(100, 100, 5);
		//drawer->setColor(Drawer::WHITE);
		
		//drawer->circle(100, 100, 50);
		//drawer->rectangle(0, 0, 150, 150);
		drawer->setColor(Drawer::BLACK);

		SDL_RenderPresent(renderer);
	}
}

void quit(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char *args[])
{

	if (!initSDL())
		return 3;

	SDL_Window *window = createWindow();
	if (!window)
		return 3;

	SDL_Renderer *renderer = createRenderer(window);
	if (!renderer)
		return 3;

	Drawer *drawer = new Drawer();
	drawer->setRenderer(renderer);

	Tablero *tablero = new Tablero();
	tablero->setDrawer(drawer);

	drawLoop(tablero, drawer, renderer);
	quit(window, renderer);

	return 0;
}