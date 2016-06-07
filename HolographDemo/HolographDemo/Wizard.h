#pragma once

#ifndef WIZARD_H_
#define WIZARD_H_

#include <string>
#include <vector>
#include "Symptom.h"
#include "Ingredient.h"
#include "ObjModel.h"

class Wizard
{
public:
	Wizard();
	std::vector<Symptom> symptoms;
	ObjModel* model;

};

#endif