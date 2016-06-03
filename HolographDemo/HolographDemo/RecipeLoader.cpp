#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Symptom.h"
#include "Ingredient.h"
#include "RecipeLoader.h"

std::vector<Ingredient> RecipeLoader::loadIngredients()
{
	std::ifstream input("Text/Ingredient.txt");
	std::vector<Ingredient> list;
	std::string line = "";

	for (std::string line; getline(input, line); )
	{
		std::vector<std::string> parts = RecipeLoader::split(line, ':');
		Ingredient ing = Ingredient(parts.at(0), parts.at(1), parts.at(2));
		list.push_back(ing);
	}
	return list;
}

std::vector<Symptom> RecipeLoader::loadSymptoms()
{
	std::ifstream input("Text/Symptom.txt");
	std::vector<Symptom> list;

	for (std::string line; getline(input, line); )
	{
		std::vector<std::string> parts = RecipeLoader::split(line, ':');
		Symptom ing = Symptom(parts.at(0), parts.at(1));
		list.push_back(ing);
	}
	return list;
}

std::vector<std::string> &RecipeLoader::split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


std::vector<std::string> RecipeLoader::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}
