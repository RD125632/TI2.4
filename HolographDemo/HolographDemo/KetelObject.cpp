#include "KetelObject.h"

KetelObject::KetelObject()
{
	model = new ObjModel("models/ketel/ketel.obj");
	type = "object";
}

KetelObject::~KetelObject()
{
}

void KetelObject::AddIngredient(std::string ingr)
{
	if(!ingr.compare("object"))
		addedIngedients.push_back(ingr);
}

std::vector<std::string> KetelObject::GetIngedients() const
{
	return addedIngedients;
}