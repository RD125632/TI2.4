#pragma once

#include <vector>
#include <string>

class Potion
{
public:
	Potion();
	bool checkIngredients(std::vector<int> symptoms, std::vector<std::string> ingredients);
	~Potion();
};

