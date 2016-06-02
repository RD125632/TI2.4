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