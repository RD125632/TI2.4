#include "Ingredient.h"

Ingredient::Ingredient()
{

}

Ingredient::Ingredient(int id, std::string newname, int s, ObjModel* modelwer, std::string Itype)
{
	ID = id;
	name = newname;
	cures = s;
	model = modelwer;
	type = Itype;
}