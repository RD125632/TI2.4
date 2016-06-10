#include "Wizard.h"
#include "RecipeLoader.h"

Wizard::Wizard()
{

}

Wizard::Wizard(std::vector<int> list)
{
	symptoms = list;
	model = new ObjModel("models/wizard/wizard.obj");
}
