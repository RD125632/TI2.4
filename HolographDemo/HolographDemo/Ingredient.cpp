#include "Ingredient.h"

Ingredient::Ingredient(std::string newname, std::string desc, std::string s)
{
	name = newname;
	description = desc;
	cures = s;
}