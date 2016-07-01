#pragma once

#include "Book.h"
#include "RecipeLoader.h"

Book::Book()
{
	model = new ObjModel("models/book/spellbook.obj");
}

Book::Book(std::vector<int> list)
{
	ingredient_IDs = list;
	model = new ObjModel("models/book/spellbook.obj");
}
