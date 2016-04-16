#include "Game.h"

#include "Time.h"
#include "Input.h"
#include "Screen.h"

#define FRAMES_PER_SECOND 1000
#define TIME_PER_FRAME (1000 / FRAMES_PER_SECOND)
#define TICKS_PER_FRAME (1.0 / FRAMES_PER_SECOND)

Game::Game ()
{
	_currentScene = new Scene ();

	Time::Init();
}

Game::~Game ()
{
	
}

Game* Game::Instance ()
{
	static Game instance;

	return &instance;
}

void Game::Start ()
{
	bool running=true;

	while(running)
	{
		Screen::Clear ();

		Time::UpdateFrame ();
		Input::UpdateState ();

        if (Input::GetQuit () || Input::GetKeyDown (27)) {
        	running = false;
        	continue;
        }

		// if (Input::GetResizeEvent () != Vector2::Zero) {
		// 	OnWindowResize (Input::GetResizeEvent ());
		// }

		_currentScene->Update ();
		_currentScene->Display ();

		Screen::Render ();

		if(TICKS_PER_FRAME > Time::GetElapsedTimeMS () - Time::GetTimeMS ()) {
			SDL_Delay(TICKS_PER_FRAME - (Time::GetElapsedTimeMS () - Time::GetTimeMS ()));
		}
	}
}