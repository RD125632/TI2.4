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
	
	room = new Room(100,100,100);
	plank = PlankObject();
	leaphandler = SampleListener();

	controller.addListener(leaphandler);
	
	ingredients = FileLoader::loadIngredients();
	symptoms = FileLoader::loadSymptoms();
	storyBegin = FileLoader::loadStory("Text/StoryIntro.txt");
	storyEnd = FileLoader::loadStory("Text/StoryOutro.txt");
	
	

	soundEngine = SoundEngine();

	/* Load Ingredients in book */
	std::vector<int> parse_IDs;
	
	for (Ingredient x : ingredients)
	{
		parse_IDs.push_back(x.ID);
	}
	for (Ingredient i : ingredients)
	{
		storyBook.push_back(i.name + ":");
		for (std::string line : i.description)
		{
			storyBook.push_back(line);
		}
		storyBook.push_back("");
		storyBook.push_back("");
	}
	book = Book(parse_IDs);
	storyBookObject = StoryBook();
	storyBookObject.posZ = 30;
	storyBookObject.posX = -15;
	potion = Potion();
	storyBookObject.posY = -5;
	/* Load Wizard Symptoms */
	parse_IDs.clear();
	for (Symptom x : symptoms)
	{
		parse_IDs.push_back(x.ID);
	}
	wizard = Wizard(parse_IDs);

	holoScreen = HologramScreen();
	storyScreen = StoryScreen();
	holoWizzard = HologramWizzard();
}

bool GlobalCollector::CompareArrays(std::array<double, 6> array1, std::array<double, 6> array2)
{
	for (unsigned int i = 0; i < array1.size(); ++i)
	{
		if (array1[i] != array2[i])
		{
			return false;
		}
	}
	return true;
}

void GlobalCollector::CopyArray(std::array<double, 6>* toCopy, std::array<double, 6>* copyTo)
{
	for(unsigned int i = 0; i < toCopy->size(); ++i)
	{
		copyTo->at(i) = toCopy->at(i);
	}
}
