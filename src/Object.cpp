#include "Object.h"

#include <string>

std::string Object::ToString() const
{
	return "";
}

bool Object::Equal(Object* other)
{
	// compare pointers
	return this == other;
}