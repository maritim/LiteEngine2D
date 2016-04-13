#include "ImageLoader.h"

#ifdef _WIN32
	#include <SDL_image.h>
#elif __linux__
	#include <SDL/SDL_image.h>
#endif

#include <string>

#include "Image.h"

Object* ImageLoader::Load(const std::string& filename)
{
	SDL_Surface* img=IMG_Load(filename.c_str());
	
	if(img==NULL) {
		exit (1);
	}

	SDL_PixelFormat pf;//={NULL,32,4,0,0,0,0,0,0,0,0,0xff000000,0x00ff0000,0x0000ff00,0x000000ff,0,255};

	pf.palette = 0;
	pf.BitsPerPixel = 32;
	pf.BytesPerPixel = 4;
	pf.alpha = 255;
	pf.Rshift = pf.Rloss = pf.Gloss = pf.Bloss = pf.Aloss = pf.colorkey = 0;
	pf.Rmask = 0x000000ff;
	pf.Gshift = 8;
	pf.Gmask = 0x0000ff00;
	pf.Bshift = 16;
	pf.Bmask = 0x00ff0000;
	pf.Ashift = 24;
	pf.Amask = 0xff000000;

	SDL_Surface* img2=SDL_ConvertSurface(img,&pf,SDL_SWSURFACE);
	if(img2==NULL) {
		exit (1);             
	}

	SDL_FreeSurface (img);

	Image* image = new Image(img2, filename);

	return image;
}