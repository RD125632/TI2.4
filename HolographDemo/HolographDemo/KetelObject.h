#pragma once
#include "SuperObject.h"

class KetelObject :
	public SuperObject
{
public:
	KetelObject();
	~KetelObject();
	void AddIngredient(SuperObject *);
	std::vector <SuperObject *> GetIngedients() const;

private:
	std::vector<SuperObject *> addedIngedients;
};
