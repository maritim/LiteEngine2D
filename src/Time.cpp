#include "Time.h"

Uint32 Time::_currentTimeMS (0);
Uint32 Time::_deltaTimeMS (0);

float Time::GetDeltaTime()
{
	return _deltaTimeMS / 1000.0f;
}

float Time::GetTime()
{
	return _currentTimeMS;
}

void Time::Init() 
{
	_currentTimeMS = SDL_GetTicks();
}

void Time::UpdateFrame()
{
	Uint32 lastTimeMS = _currentTimeMS;
	_currentTimeMS = SDL_GetTicks();

	_deltaTimeMS = _currentTimeMS - lastTimeMS;
}

unsigned int Time::GetDeltaTimeMS ()
{
	return _deltaTimeMS;
}

/*
 * Get ticks since the start of the game until the start of current frame.
*/

unsigned int Time::GetTimeMS ()
{
	return _currentTimeMS;
}

/* 
 * Get ticks since the start of the game until the current moment.
*/

unsigned int Time::GetElapsedTimeMS ()
{
	return SDL_GetTicks ();
}