#pragma once

#ifndef STATE_MANAGER_H_
#define STATE_MANAGER_H_

#include <string>
#include "Screen.h"
#include "HologramScreen.h"
#include "StoryScreen.h"
#include <vector>

class Statemanager
{
public:
	Statemanager(int hologramWindow, int storyWindow);
	int Gamestate;
	int HologramState;
	int StoryState;
	std::vector<HologramScreen> HologramScreens;
	std::vector<StoryScreen> StoryScreens;
};

#endif