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
#include "Potion.h"
#include "PlankObject.h"
#include "Pollspoon.h"
#include "Room.h"
#include "Camera.h"
#include "WorldObject.h"
#include <vector>
#include "Sound.h"
#include "LeapHandler.h"
#include "StoryBook.h"
#include "HologramWizzard.h"
#include <time.h>

class GlobalCollector
{
public:
	static GlobalCollector* Instance();
	Room* room;
	HologramScreen holoScreen;
	StoryScreen storyScreen;
	Book book;
	StoryBook storyBookObject;
	Wizard wizard;
	KetelObject ketel;
	Potion potion;
	PlankObject plank;
	Pollspoon pollspoon;
	Camera camera;
	std::vector<Ingredient> ingredients;
	std::vector<Symptom> symptoms;
	SoundEngine soundEngine;
	SampleListener leaphandler;
	Controller controller;
	std::vector<string> storyBegin;
	std::vector<string> storyEnd;
	std::vector<string> storyBook;
	HologramWizzard holoWizzard;
	static bool CompareArrays(std::array<double, 6>, std::array<double, 6>);
	static void CopyArray(std::array<double, 6>*, std::array<double, 6>*);
	time_t oldTimeForSwipe = 0;

private:
	GlobalCollector();
	static GlobalCollector* instance;
};

#endif