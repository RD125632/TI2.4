#pragma once

#ifndef GLOBAL_COLLECTOR_H_
#define GLOBAL_COLLECTOR_H_

#include <string>
#include "HologramScreen.h"
#include "StoryScreen.h"
#include "Book.h"
#include "Wizard.h"
#include "Ingredient.h"
#include "RecipeLoader.h"
#include "KetelObject.h"
#include "PlankObject.h"
#include "Pollspoon.h"
#include <vector>

class GlobalCollector
{
public:
	static GlobalCollector* Instance();
	Room *room = new Room(100);
	HologramScreen holoScreen;
	StoryScreen storyScreen;
	Book book;
	Wizard wizard;
	KetelObject ketel;
	PlankObject plank;
	Pollspoon pollspoon;
	std::vector<Ingredient> ingredients;
	std::vector<Symptom> symptoms;

private:
	GlobalCollector();
	static GlobalCollector* instance;
};

#endif