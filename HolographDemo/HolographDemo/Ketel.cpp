#include "Ketel.h"





Ketel::Ketel( float x, float y, float z)
{
	this->model = new ObjModel("models/ketel/ketel.obj");
	this->x = x;
	this->y = y;
	this->z = z;
}

void Ketel::draw()
{
	model->draw();
}
