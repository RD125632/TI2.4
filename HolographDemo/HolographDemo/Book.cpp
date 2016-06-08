#include "Book.h"
#include "RecipeLoader.h"

Book::Book()
{

}

Book::Book(std::vector<int> list)
{
	ingredient_IDs = list;
	model = new ObjModel("models/tooth/object.obj");
}
