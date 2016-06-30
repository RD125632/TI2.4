#pragma once

#ifndef STORYSCREEN_H_
#define STORYSCREEN_H_

#include "Screen.h"
#include "Camera.h"

class StoryScreen: public Screen
{
public:
	StoryScreen();

	int Display() override;
	int Setup(int,int) override;
	bool isUpsideDown = false;
	int Status = 0;
	void SwitchScreens(int screen);
private:
	void (StoryScreen::*screenToDraw)();
	void drawIntroScreen();
	void drawGameScreen();
};

#endif