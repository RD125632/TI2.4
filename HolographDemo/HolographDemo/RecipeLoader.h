#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Symptom.h"
#include "Ingredient.h"

namespace RecipeLoader {
	std::vector<Ingredient> loadIngredients();
	std::vector<Symptom> loadSymptoms();
	std::vector<std::string> split(const std::string &s, char delim);
	std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
};