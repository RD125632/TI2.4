#pragma once

#include "Ingredient.h"
#include <vector>

class Recipe
{
public:
	std::vector<Ingredient> ingredients;
	std::string symptom;
	std::string name;
	int id;
};
