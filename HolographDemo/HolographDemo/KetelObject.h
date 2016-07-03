#pragma once
#include "SuperObject.h"
#include <string>

class KetelObject :
	public SuperObject
{
public:
	KetelObject();
	~KetelObject();
	void AddIngredient(std::string);
	std::vector <std::string> GetIngredients() const;

private:
	std::vector<std::string> addedIngredients;
};
