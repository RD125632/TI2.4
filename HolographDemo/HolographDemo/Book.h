#pragma once

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <vector>
#include "Symptom.h"
#include "Ingredient.h"
#include "ObjModel.h"

class Book
{
public:
	Book();
	std::vector<Ingredient> ingredients;
	ObjModel* model;

};

#endif