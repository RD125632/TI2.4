#include "Ingredient.h"

Ingredient::Ingredient()
{

}

Ingredient::Ingredient(std::string newname, int s, ObjModel* modelwer)
{
	name = newname;
	cures = s;
	model = modelwer;	
}