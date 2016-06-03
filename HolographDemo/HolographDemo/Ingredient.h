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
	Ingredient(std::string, int);
	std::string name;
	int cures;
	ObjModel* models;
};



#endif