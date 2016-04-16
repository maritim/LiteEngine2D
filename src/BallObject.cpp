#include "BallObject.h"

#include "Resources.h"

#include "Screen.h"
#include "Input.h"
#include "Time.h"
#include "Vector2.h"

#include <cstdlib>

#define BALL_SPEED 1000

BallObject::BallObject () :
	_speed (BALL_SPEED),
	_position (20, 20)
{
	_image = Resources::LoadImage ("Assets/Images/Ball.png");

	// This need to be deleted too
	_position = Vector2 (rand () % Screen::GetWidth (), rand () % Screen::GetHeight ());
}

BallObject::~BallObject ()
{
	delete _image;
}

void BallObject::Draw ()
{
	Screen::Draw (_image, _position);
}

void BallObject::Update ()
{
	// Uncomment this to switch the controls of the ball to keyboard

	// Vector2 velocity = Vector2::Zero;

	// if (Input::GetKey ('w')) {
	// 	velocity += Vector2::Up;
	// }
	// if (Input::GetKey ('d')) {
	// 	velocity += Vector2::Right;
	// }
	// if (Input::GetKey ('s')) {
	// 	velocity += Vector2::Down;
	// }
	// if (Input::GetKey ('a')) {
	// 	velocity += Vector2::Left;
	// }

	// if (velocity == Vector2::Zero) {
	// 	return;
	// }

	// velocity.Normalize ();

	// _position += velocity * _speed * Time::GetDeltaTime (); 

	_destination = Input::GetMousePosition ();
	_destination.SetY (Screen::GetHeight () - _destination.GetY ());

	Vector2 velocity = _destination - _position;

	if (velocity.SqrMagnitude () < 0.1f) {
		return;
	}

	velocity.Normalize ();

	_position += velocity * _speed * Time::GetDeltaTime ();
}