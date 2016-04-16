#ifndef GAMETIME_H
#define GAMETIME_H

#include <stdint.h>

#if defined(__linux__) || defined(__APPLE__)
	#include <SDL2/SDL.h>
#elif _Win32
	#include <SDL.h>
#endif

class GameTime
{
private:
	static uint32_t _currentTimeMS;
	static uint32_t _deltaTimeMS;
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