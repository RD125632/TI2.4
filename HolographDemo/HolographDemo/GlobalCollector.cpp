#include "GlobalCollector.h"
#include "GL\glut.h"

GlobalCollector* GlobalCollector::instance = NULL;

GlobalCollector * GlobalCollector::Instance()
{
	if (!instance)
	{
		instance = new GlobalCollector();
	}
	return instance;
}

GlobalCollector::GlobalCollector()
{
	holoScreen = HologramScreen();
	storyScreen = StoryScreen();
	room = new Room(100,100,100);
	plank = PlankObject();
	storyBook = StoryBook();
	storyBook.posX = -30;
	storyBook.posY = -10;
	storyBook.posZ = 50;
	ingredients = RecipeLoader::loadIngredients();
	symptoms = RecipeLoader::loadSymptoms();

	std::vector<int> parse_IDs;
	
	for (Ingredient x : ingredients)
	{
		parse_IDs.push_back(x.ID);
	}
	book = Book(parse_IDs);
	
	parse_IDs.clear();
	for (Symptom x : symptoms)
	{
		parse_IDs.push_back(x.ID);
	}
	wizard = Wizard(parse_IDs);
	
}
