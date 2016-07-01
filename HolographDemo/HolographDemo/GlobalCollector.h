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
#include "Sound.h"
#include "LeapHandler.h"

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
	SoundEngine soundEngine;
	SampleListener leaphandler;
	Controller controller;
	std::vector<string> storyBegin;
	std::vector<string> storyEnd;

private:
	GlobalCollector();
	static GlobalCollector* instance;
};

#endif