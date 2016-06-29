#include "StoryScreen.h"
#include "GlobalCollector.h"
#include "Ingredient.h"
#include <iostream>

StoryScreen::StoryScreen() : Screen()
{
	
	screenToDraw = &StoryScreen::drawIntroScreen;
}
void StoryScreen::drawIntroScreen()
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1000, 0, 1000, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glRasterPos2i(100, 120);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
	glPopMatrix();
}
void StoryScreen::drawGameScreen()
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
	GlobalCollector::Instance()->wizard.draw();


	glPopMatrix();
	glFlush();
	glutSwapBuffers();

	
}
int StoryScreen::Display()
{
	(this->*screenToDraw)();
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


	gluLookAt(GlobalCollector::Instance()->camera.currentlocation[0], GlobalCollector::Instance()->camera.currentlocation[1], GlobalCollector::Instance()->camera.currentlocation[2],
		0, 20, 20,
		0, 1, 0);
	std::cout << GlobalCollector::Instance()->camera.currentlocation[0] << GlobalCollector::Instance()->camera.currentlocation[1] << GlobalCollector::Instance()->camera.currentlocation[2] << endl;

	return 1;
}
