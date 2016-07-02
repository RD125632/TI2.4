#include "Ingredient.h"

Ingredient::Ingredient()
{

}

Ingredient::Ingredient(int id, std::string newname, int s, ObjModel* modelwer, std::string Itype, std::vector<string> desc)
{
	ID = id;
	name = newname;
	cures = s;
	model = modelwer;
	type = Itype;
	description = desc;
}