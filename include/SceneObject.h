#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "Object.h"

class SceneObject : public Object
{
public:
	SceneObject ();
	virtual ~SceneObject ();

	virtual void Update ();
	virtual void Draw ();
};

#endif