#include "StoryScreen.h"
#include <iostream>

StoryScreen::StoryScreen() : Screen()
{
	
}

int StoryScreen::Display()
{

	//Models
	glPolygonMode(GL_FRONT_AND_BACK, mode);

	glPushMatrix();
	room.draw();
	for (auto m : objects)
	{
		m->draw();
	}
	glPopMatrix();
	glFlush();
	glutSwapBuffers();

	return 0;
}

int StoryScreen::Setup(int windowWidth, int windowHeight)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glViewport(0, 0, windowWidth, windowHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(90, (float)windowWidth / windowHeight, 0.1f, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(camera.currentlocation[0], camera.currentlocation[1], camera.currentlocation[2],
		0, 0, 0,
		0, 1, 0);

	return 1;
}