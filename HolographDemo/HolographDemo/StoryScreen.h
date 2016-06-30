#pragma once

#ifndef STORYSCREEN_H_
#define STORYSCREEN_H_

#include "Screen.h"
#include "Camera.h"

class StoryScreen: public Screen
{
public:
	Camera camera = Camera();
	StoryScreen();
	int Display() override;
	int Setup(int,int) override;
	bool isUpsideDown = false;
};

#endif