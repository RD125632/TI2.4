#pragma once

#include <vector>

namespace RecipeLoader {
	std::vector<Ingredient> loadIngredients();
	std::vector<Symptom> loadSymptoms();
	std::vector<std::string> split(const std::string &s, char delim);
	std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
};