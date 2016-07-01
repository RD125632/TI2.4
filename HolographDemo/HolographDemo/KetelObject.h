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
	std::vector <std::string> GetIngedients() const;

private:
	std::vector<std::string> addedIngedients;
};
