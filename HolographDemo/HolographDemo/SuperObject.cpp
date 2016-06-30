#include "SuperObject.h"

void SuperObject::SetType(IngredientType a)
{
	type = a;
}

IngredientType SuperObject::GetType() const
{
	return type;
}
