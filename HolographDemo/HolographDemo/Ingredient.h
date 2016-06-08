#pragma once

#ifndef INGREDIENT_H_
#define INGREDIENT_H_

#include <string>
#include <vector>
#include "Symptom.h"
#include "ObjModel.h"

class Ingredient
{
public:
	Ingredient();
	Ingredient(std::string, int, ObjModel*);
	std::string name;
	int cures;
	ObjModel* model;
};



#endif