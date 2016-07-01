#pragma once

#include "RecipeLoader.h"

std::vector<string> FileLoader::loadStory(string filePath)
{
	std::ifstream input(filePath);
	std::vector<string> list;

	for (std::string line; getline(input, line); )
	{
		list.push_back(line);
	}

	return list;
}

std::vector<Ingredient> FileLoader::loadIngredients()
{
	std::ifstream input("Text/Ingredient.txt");
	std::vector<Ingredient> list;
	std::string line = "";

	for (std::string line; getline(input, line); )
	{
		std::string::size_type sz;
		std::vector<std::string> parts = FileLoader::split(line, ':');
		std::vector<std::string> descParts = FileLoader::split(parts.at(4), '.');
		Ingredient ing = Ingredient(std::stoi(parts.at(0), &sz), parts.at(1), std::stoi(parts.at(2), &sz), new ObjModel("models/"+ parts.at(3) +"/object.obj"), parts.at(3), descParts);
		list.push_back(ing);
	}
	return list;
}

std::vector<Symptom> FileLoader::loadSymptoms()
{
	std::ifstream input("Text/Symptom.txt");
	std::vector<Symptom> list;
	std::vector<Symptom> chosenOnes;

	for (std::string line; getline(input, line); )
	{
		std::string::size_type sz;
		std::vector<std::string> parts = FileLoader::split(line, ':');
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

std::vector<std::string> &FileLoader::split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


std::vector<std::string> FileLoader::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}
