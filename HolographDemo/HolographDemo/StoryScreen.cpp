#include "StoryScreen.h"
#include "GlobalCollector.h"
#include "Ingredient.h"
#include <iostream>

StoryScreen::StoryScreen() : Screen()
{
	
}

int StoryScreen::Display()
{
	//Models
	glPolygonMode(GL_FRONT_AND_BACK, mode);
	glPushMatrix();
	GlobalCollector::Instance()->room->draw();
	
	if (!isUpsideDown)
	{
		glScalef(-1, 1, 1);
	}
	else
	{
		glScalef(-1, -1, 1);
	}
	
	GlobalCollector::Instance()->plank.draw();
	//glTranslated(-25, 25, 45);
	for (Ingredient ing : GlobalCollector::Instance()->ingredients)
	{
		ing.draw();
		//glTranslated(5, 0, 0);
	}
	
	
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

	gluPerspective(90, (float)windowWidth / windowHeight, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	gluLookAt(0, 40, zoom,
		0, 40, 20,
		0, 1, 0);
	std::cout << camera.currentlocation[0] << camera.currentlocation[1] << camera.currentlocation[2] << endl;

	return 1;
}
