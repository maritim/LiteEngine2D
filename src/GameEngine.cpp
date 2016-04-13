#ifdef __linux__
	#include <SDL/SDL.h>
#elif __MINGW32__
	#include <SDL.h>
#elif __APPLE__
	#include <SDL.h>
#endif

#include "GameEngine.h"

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