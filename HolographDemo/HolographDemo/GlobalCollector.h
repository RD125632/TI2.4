#pragma once

#ifndef GLOBAL_COLLECTOR_H_
#define GLOBAL_COLLECTOR_H_

#include <string>
#include "HologramScreen.h"
#include "StoryScreen.h"
#include "Book.h"
#include "StoryBook.h"
#include "Wizard.h"
#include "Ingredient.h"
#include "RecipeLoader.h"
#include "KetelObject.h"
#include "PlankObject.h"
#include "Pollspoon.h"
#include "Room.h"
#include "Camera.h"
#include "WorldObject.h"
#include <vector>

class GlobalCollector
{
public:
	static GlobalCollector* Instance();
	Room* room;
	HologramScreen holoScreen;
	StoryScreen storyScreen;
	Book book;
	StoryBook storyBook;
	Wizard wizard;
	KetelObject ketel;
	PlankObject plank;
	Pollspoon pollspoon;
	Camera camera;
	std::vector<Ingredient> ingredients;
	std::vector<Symptom> symptoms;
	std::vector<tmp12::WorldObject> effects;

private:
	GlobalCollector();
	static GlobalCollector* instance;
};

#endif