#include "ImageLoader.h"

#ifdef _WIN32 || __APPLE__
	#include <SDL_image.h>
#elif __linux__
	#include <SDL2/SDL_image.h>
#endif

#include <string>

#include "Image.h"

Object* ImageLoader::Load(const std::string& filename)
{
	SDL_Surface* img=IMG_Load(filename.c_str());

	Image* image = new Image(img, filename);

	return image;
}