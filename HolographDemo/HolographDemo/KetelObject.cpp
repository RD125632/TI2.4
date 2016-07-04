#include "KetelObject.h"
#include "GlobalCollector.h"

KetelObject::KetelObject()
{
	model = new ObjModel("models/ketel/ketel.obj");
	type = "object";
}

KetelObject::~KetelObject()
{
}

void KetelObject::AddIngredient(std::string ingr)
{
	if(ingr != "object" )
		addedIngredients.push_back(ingr);
	if (GlobalCollector::Instance()->potion.checkIngredients(GlobalCollector::Instance()->wizard.symptoms, GetIngredients()))
		GlobalCollector::Instance()->storyScreen.SwitchScreens(4);
}

std::vector<std::string> KetelObject::GetIngredients() const
{
	return addedIngredients;
}