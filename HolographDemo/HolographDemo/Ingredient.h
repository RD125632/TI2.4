#pragma once

#ifndef INGREDIENT_H_
#define INGREDIENT_H_

#include <string>
#include <vector>
#include "SuperObject.h"
#include "ObjModel.h"

class Ingredient : public SuperObject
{
public:
	Ingredient();
	Ingredient(int, std::string, int, ObjModel*, std::string, std::vector<string>);
	std::string name;
	int cures;
	std::vector<string> description;
	bool operator ==(const Ingredient &);
};



#endif