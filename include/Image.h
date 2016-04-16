#ifndef IMAGE_H
#define IMAGE_H

#ifdef __linux__
	#include <SDL2/SDL.h>
#elif _WIN32 || __APPLE__
	#include <SDL.h>
#endif

#include <string>

#include "Object.h"

class Image : public Object
{
private:
	SDL_Surface* _surface;
	std::string _name;

public:
	Image (SDL_Surface* surface, const std::string& name);
	~Image ();

	SDL_Surface* GetSurface () const;

	std::size_t GetHeight () const;
	std::size_t GetWidth () const;
};

#endif