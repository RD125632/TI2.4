#ifndef STORYSCREEN_H_
#define STORYSCREEN_H_

#include "Screen.h"
#include "Camera.h"

class StoryScreen: public Screen
{
public:
	StoryScreen();
	void init();
	int Display() override;
	int Setup(int,int) override;

	bool isUpsideDown = false;
	GLfloat UpwardsScrollVelocity = -10.0;
	float view = 20.0;
	Texture * background;
	int Status = 0;
	int storyStatus = 0;
	void SwitchScreens(int screen);
	void PrepareScoreScreen();
	void Logic();
private:
	void drawBackground();
	void (StoryScreen::*screenToDraw)();
	void drawIntroScreen();
	void drawGameScreen();
	void drawScoreScreen();
	int screen;
};

#endif