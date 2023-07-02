/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

// Using SDL and standard IO
#include "SDL2/SDL.h"
#include <stdio.h>
#include <iostream>
#include "Drawer.h"
#include "Game.h"
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



SDL_Event getEvent()
{
	SDL_Event event;
	SDL_WaitEvent(&event);

	return event;
}

void handleKeyboardEvents(Game *game, Uint32 eventType, SDL_KeyboardEvent key)
{
	Cursor &cursor = game->getCursor();

	if (eventType != SDL_KEYDOWN)
		return;
	
	SDL_Scancode code = key.keysym.scancode;

	if (code == SDL_SCANCODE_DOWN)
		cursor.abajo();

	if (code == SDL_SCANCODE_UP)
		cursor.arriba();

	if (code == SDL_SCANCODE_RIGHT)
		cursor.derecha();

	if (code == SDL_SCANCODE_LEFT)
		cursor.izquierda();

	if (code == SDL_SCANCODE_KP_ENTER || code == SDL_SCANCODE_RETURN) {
		int numMovtos = game->realizarMovimiento();
		if (numMovtos > 0) {
			game->cambiarTurno();
		}
	}
		

	if (code == SDL_SCANCODE_ESCAPE)
		game->deseleccionar();

}

void drawLoop(Game *game, Drawer *drawer, SDL_Renderer *renderer)
{

	while (true)
	{
		SDL_Event event = getEvent();
		if (event.type == SDL_QUIT)
		{
			break;
		}

		handleKeyboardEvents(game, event.type, event.key);

		SDL_RenderClear(renderer);

		game->pintarTablero();
		game->pintarCursor();
		game->pintarSeleccion();
		game->pintarMarcador();

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

	Game *game = new Game();
	game->setDrawer(drawer);

	drawLoop(game, drawer, renderer);
	quit(window, renderer);

	return 0;
}