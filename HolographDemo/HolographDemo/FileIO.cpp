#include <string>
#include <fstream>
#include <vector>
#include "Ingredient.h"
#include "FileIO.h"

FileIO::FileIO()
{
	std::ifstream input("Text/Ingredient.txt");
	std::vector<Ingredient> list;

	for (std::string line; getline(input, line); )
	{
		Ingredient ing = Ingredient(line);
		list.push_back(ing);
	}
}

