#pragma once

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <vector>
#include "Ingredient.h"
#include "SuperObject.h"

class Book: public SuperObject
{
public:
	Book();
	Book(std::vector<int>);
	std::vector<int> ingredient_IDs;
};

#endif