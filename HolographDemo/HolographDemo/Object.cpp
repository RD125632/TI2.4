#include "Object.h"

Object::Object(float x, float y, float z, std::string path) : ObjModel(path)
{
	this->location = new Vec3f(x, y, z);
}

Object::Object(Vec3f* location, std::string path) : ObjModel(path)
{
	this->location = location;
}

void Object::Draw()
{
	ObjModel::draw();
}

Vec3f* Object::getLocation()
{
	return location;
}

void Object::setLocation(Vec3f* newLocation)
{
	location = newLocation;
}
