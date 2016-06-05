#pragma once

#ifndef STORYSCREEN_H_
#define STORYSCREEN_H_

#include <string>
#include <vector>
#include "ObjModel.h"
#include "Screen.h"
#include "Room.h"
#include "Camera.h"

class StoryScreen: public Screen
{
public:
	Room room = Room(10);
	Camera camera = Camera();
	StoryScreen();
	int Display() override;
	int Setup(int,int) override;
};

#endif