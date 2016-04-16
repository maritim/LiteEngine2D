// Use SDL_GetTicks()
// Probably need to replace this with own time wrapper

#ifndef TIME_H
#define TIME_H

#ifdef __linux__
	#include <SDL2/SDL.h>
#elif _Win32 || __APPLE__
	#include <SDL.h>
#endif

class Time
{
private:
	static Uint32 _currentTimeMS;
	static Uint32 _deltaTimeMS;
public:
	static void Init();
	static void UpdateFrame();

	static float GetDeltaTime();
	static float GetTime();

	static unsigned int GetDeltaTimeMS ();
	static unsigned int GetTimeMS ();

	static unsigned int GetElapsedTimeMS ();
};

#endif