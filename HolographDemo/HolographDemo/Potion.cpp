#include "Potion.h"
#include "GlobalCollector.h"


Potion::Potion()
{

}

bool Potion::checkIngredients(vector<int> symptoms, vector<string> ingredients)
{
	for (string ingredientname : ingredients)
	{
		for (Ingredient ingredient : GlobalCollector::Instance()->ingredients)
		{
			if (ingredient.name == ingredientname)
			{
				for (unsigned int i = 0; i < symptoms.size(); i++)
				{
					if (symptoms[i] == ingredient.cures)
					{
						symptoms.erase(symptoms.begin() + i);
					}
				}
			}
		}
	}
	if (symptoms.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


Potion::~Potion()
{

}
