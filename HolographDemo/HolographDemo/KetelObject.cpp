#include "KetelObject.h"

KetelObject::KetelObject()
{
	model = new ObjModel("models/ketel/ketel.obj");
	type = none;
}

KetelObject::~KetelObject()
{
}

void KetelObject::AddIngredient(IngredientType ingr)
{
	addedIngedients.push_back(ingr);
}

std::vector<IngredientType> KetelObject::GetIngedients() const
{
	return addedIngedients;
}