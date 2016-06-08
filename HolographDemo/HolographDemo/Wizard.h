#pragma once

#ifndef WIZARD_H_
#define WIZARD_H_

#include <string>
#include <vector>
#include "Symptom.h"
#include "Ingredient.h"
#include "ObjModel.h"

class Wizard : SuperObject
{
public:
	Wizard();
	Wizard(std::vector<int>);
	std::vector<int> symptoms;
};

#endif