#include "Book.h"
#include "RecipeLoader.h"

Book::Book()
{
	ingredients = RecipeLoader::loadIngredients();
	model = new ObjModel("models/book/spellbook.obj");
}
