#include "Wizard.h"
#include "RecipeLoader.h"

Wizard::Wizard()
{

}

Wizard::Wizard(std::vector<int> list)
{
	symptoms = list;
	type = "object";
	model = new ObjModel("models/wizard/wizard.obj");
}
