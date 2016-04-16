#ifndef INPUT_H
#define INPUT_H

#include "Vector2.h"

#if defined(__linux__) || defined(__APPLE__)
	#include <SDL2/SDL.h>
#elif _WIN32
	#include <SDL.h>
#endif

class Input
{
private:
	static bool _keyState[256];
	static bool _lastKeyState[256];
	static bool _lastMouseState[4];
	static bool _mouseState[4];
	static bool _sdlQuit;
	static Vector2 _resizeEvent;
public:
	static bool GetButton (SDL_Keycode key);
	static bool GetButtonDown (SDL_Keycode key);
	static bool GetButtonUp (SDL_Keycode key);

	static bool GetKey (unsigned char key);
	static bool GetKeyDown (unsigned char key);
	static bool GetKeyUp (unsigned char key);

	static bool GetMouseButton (Uint8 button);
	static bool GetMouseButtonDown (Uint8 button);
	static bool GetMouseButtonUp (Uint8 button);
	static Vector2 GetMousePosition ();

	static bool GetQuit ();
	static Vector2 GetResizeEvent ();

	static void UpdateState ();
};

#endif