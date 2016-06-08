#include "RecipeLoader.h"

std::vector<Ingredient> RecipeLoader::loadIngredients()
{
	std::ifstream input("Text/Ingredient.txt");
	std::vector<Ingredient> list;
	std::string line = "";

	for (std::string line; getline(input, line); )
	{
		std::string::size_type sz;
		std::vector<std::string> parts = RecipeLoader::split(line, ':');
		Ingredient ing = Ingredient(std::stoi(parts.at(0), &sz), parts.at(1), std::stoi(parts.at(2), &sz), new ObjModel("models/"+ parts.at(3) +"/" + parts.at(3) + ".obj"));
		list.push_back(ing);
	}
	return list;
}

std::vector<Symptom> RecipeLoader::loadSymptoms()
{
	std::ifstream input("Text/Symptom.txt");
	std::vector<Symptom> list;
	std::vector<Symptom> chosenOnes;

	for (std::string line; getline(input, line); )
	{
		std::string::size_type sz;
		std::vector<std::string> parts = RecipeLoader::split(line, ':');
		Symptom ing = Symptom(std::stoi(parts.at(0), &sz), parts.at(1), parts.at(2));
		list.push_back(ing);
	}
	
	int v1, v2, v3;
	v1 = rand() % list.size();
	v2 = rand() % list.size();
	v3 = rand() % list.size();

	while (v2 == v1)
	{
		v2 = rand() % list.size();
	}
	while (v3 == v2 || v3 == v1)
	{
		v3 = rand() % list.size();
	}

	chosenOnes.push_back(list.at(v1));
	chosenOnes.push_back(list.at(v2));
	chosenOnes.push_back(list.at(v3));

	return chosenOnes;
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
