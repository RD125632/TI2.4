#include "KetelObject.h"

KetelObject::KetelObject()
{
	model = new ObjModel("models/ketel/ketel.obj");
}

KetelObject::~KetelObject()
{
}

void KetelObject::AddIngredient(SuperObject* ingr)
{
	addedIngedients.push_back(ingr);
}

std::vector<SuperObject *> KetelObject::GetIngedients() const
{
	return addedIngedients;
}