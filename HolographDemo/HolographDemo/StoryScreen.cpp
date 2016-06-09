#include "StoryScreen.h"
#include "GlobalCollector.h"
#include <iostream>

StoryScreen::StoryScreen() : Screen()
{
	
}

int StoryScreen::Display()
{
	//Models
	glPolygonMode(GL_FRONT_AND_BACK, mode);

	glPushMatrix();
	
	//GlobalCollector::Instance()->room->draw();
	GlobalCollector::Instance()->book.draw();
	
	glPopMatrix();
	glFlush();
	glutSwapBuffers();

	return 0;
}

int StoryScreen::Setup(int windowWidth, int windowHeight)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.00392156862f, 0.00784313725f, 0.01176470588f, 1.0f);

	glViewport(0, 0, windowWidth, windowHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(90, (float)windowWidth / windowHeight, 0.1f, 200);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 0, -zoom,
		0, 0, 0,
		0, 1, 0);

	return 1;
}