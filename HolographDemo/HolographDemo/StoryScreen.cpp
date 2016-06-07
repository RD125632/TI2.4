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
	glScalef(-zoom, zoom, zoom);
	glRotatef(rotateX, 1, 0, 0);
	glRotatef(rotateY, 0, 1, 0);
	for (auto m : models)
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

	glViewport(0, 0, 1920, 1080);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(90, 1920 / 1080, -10, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 1, -4,
		0, 0, 0,
		0, 1, 0);

	return 1;
}