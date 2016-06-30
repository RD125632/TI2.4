#include "SuperObject.h"

SuperObject::SuperObject()
{
	EnumParser<IngredientType> parser;
}

void SuperObject::SetType(IngredientType a)
{
	type = a;
}

IngredientType SuperObject::GetType() const
{
	return type;
}
