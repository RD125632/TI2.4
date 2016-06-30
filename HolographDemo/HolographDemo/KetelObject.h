#pragma once
#include "SuperObject.h"

class KetelObject :
	public SuperObject
{
public:
	KetelObject();
	~KetelObject();
	void AddIngredient(IngredientType);
	std::vector <IngredientType> GetIngedients() const;

private:
	std::vector<IngredientType> addedIngedients;
};
