#include "PlankObject.h"

PlankObject::PlankObject()
{
	model = new ObjModel("models/plank/object.obj");
	type = none;
}

PlankObject::~PlankObject()
{
}