#include "PlankObject.h"

PlankObject::PlankObject()
{
	model = new ObjModel("models/plank/plank.obj");
	type = "object";
}

PlankObject::~PlankObject()
{
}