#include "Ingredient.h"

Ingredient::Ingredient()
{

}

Ingredient::Ingredient(int id, std::string newname, int s, ObjModel* modelwer)
{
	ID = id;
	name = newname;
	cures = s;
	model = modelwer;	
}