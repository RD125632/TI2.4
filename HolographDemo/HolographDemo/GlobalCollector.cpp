#include "GlobalCollector.h"
#include "GL\glut.h"
#include <stdio.h> 

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
	leaphandler = SampleListener();

	controller.addListener(leaphandler);
	std::cout << "Press Enter to quit..." << std::endl;
	ingredients = RecipeLoader::loadIngredients();
	symptoms = RecipeLoader::loadSymptoms();
	soundEngine = SoundEngine();

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
