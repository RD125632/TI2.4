#include "Wizard.h"
#include "RecipeLoader.h"

Wizard::Wizard()
{
	symptoms = RecipeLoader::loadSymptoms();
	model = new ObjModel("models/book/spellbook.obj");
}
