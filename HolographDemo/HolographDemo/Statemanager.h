#pragma once

#ifndef STATE_MANAGER_H_
#define STATE_MANAGER_H_

#include <string>
#include "Screen.h"
#include <vector>

class Statemanager
{
public:
	Statemanager();
	int Gamestate;
	int HologramState;
	int StoryState;
	std::vector<Screen> HologramScreens;
	std::vector<Screen> StoryScreens;
};

#endif