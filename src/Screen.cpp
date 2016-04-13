#include "Screen.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

SDL_Surface* Screen::_surface (nullptr);

void Screen::Init ()
{
	_surface = SDL_SetVideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, 0, SDL_HWSURFACE | SDL_DOUBLEBUF );
}

void Screen::Quit ()
{
	SDL_FreeSurface (_surface);	
}

void Screen::Clear ()
{
	SDL_FillRect(_surface, NULL, 0x000000);
}

void Screen::Draw (Image* image, const Vector2& pos)
{
	// Part of the screen we want to draw the sprite to
	SDL_Rect destination;
	destination.x = pos.GetX ();
	destination.y = _surface->h - pos.GetY ();
	destination.w = _surface->w;
	destination.h = _surface->h;

	SDL_BlitSurface(image->GetSurface (), NULL, _surface, &destination);
}

void Screen::Flip ()
{
	SDL_Flip (_surface);
}

std::size_t Screen::GetWidth ()
{
	return _surface->w;
}

std::size_t Screen::GetHeight ()
{
	return _surface->h;
}