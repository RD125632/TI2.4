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
	
	room = new Room(100,100,100);
	plank = PlankObject();
	
	ingredients = FileLoader::loadIngredients();
	symptoms = FileLoader::loadSymptoms();
	storyBegin = FileLoader::loadStory("Text/StoryIntro.txt");
	storyEnd = FileLoader::loadStory("Text/StoryEnding.txt");

	soundEngine = SoundEngine();

	/* Load Ingredients in book */
	std::vector<int> parse_IDs;
	
	for (Ingredient x : ingredients)
	{
		parse_IDs.push_back(x.ID);
	}
	book = Book(parse_IDs);
	
	/* Load Wizard Symptoms */
	parse_IDs.clear();
	for (Symptom x : symptoms)
	{
		parse_IDs.push_back(x.ID);
	}
	wizard = Wizard(parse_IDs);




	holoScreen = HologramScreen();
	storyScreen = StoryScreen();
}
