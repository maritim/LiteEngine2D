#include "GameEngine.h"

#ifdef __linux__
	#include <SDL2/SDL.h>
#elif _Win32 || __APPLE__
	#include <SDL.h>
#endif

#include "Screen.h"

void GameEngine::Init ()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Screen::Init ();
}

void GameEngine::Quit ()
{	
	Screen::Quit ();

	SDL_Quit();
}