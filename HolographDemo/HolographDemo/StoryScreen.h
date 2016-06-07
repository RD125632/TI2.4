#pragma once

#ifndef STORYSCREEN_H_
#define STORYSCREEN_H_

#include <string>
#include <vector>
#include "ObjModel.h"
#include "Screen.h"

class StoryScreen: public Screen
{
public:
	StoryScreen();
	int Display() override;
	int Setup(int,int) override;
};

#endif