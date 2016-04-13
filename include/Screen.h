#ifndef SCREEN_H
#define SCREEN_H

#include <SDL/SDL.h>

#include <cstddef>

#include "Image.h"
#include "Vector2.h"

class Screen
{
private:
	static SDL_Surface* _surface;

public:
	static void Init ();
	static void Quit (); 

	static void Draw (Image* image, const Vector2& pos);

	static void Flip ();
	static void Clear ();

	static std::size_t GetWidth ();
	static std::size_t GetHeight ();
};

#endif