#ifndef BALLOBJECT_H
#define BALLOBJECT_H

#include "Image.h"

#include "SceneObject.h"
#include "Vector2.h"

class BallObject : public SceneObject
{
private:
	Image* _image;
	float _speed;
	Vector2 _position;
	Vector2 _destination;

public:
	BallObject ();
	~BallObject ();

	virtual void Draw ();
	virtual void Update ();
};

#endif