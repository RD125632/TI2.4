#include "HologramScreen.h"
#include <iostream>
#include "GlobalCollector.h"

HologramScreen::HologramScreen() : Screen()
{
	currentModel = 0;
}

int HologramScreen::Display()
{
	//Models
	glPolygonMode(GL_FRONT_AND_BACK, mode);
	glPushMatrix();
	if (!isUpsideDown)
	{
		glScalef(-1, 1, 1);
	}
	else
	{
		glScalef(-1, -1, 1);
	}

	/* SET POSITION AND ROTATION */
	//GlobalCollector::Instance()->ingredients.at(2).rotZ = 50;
	//GlobalCollector::Instance()->ingredients.at(2).posX = 2;
	//GlobalCollector::Instance()->ingredients.at(0).draw();
	glRotatef(rotateX, 1, 0, 0);
	glRotatef(rotateY, 0, 1, 0);
	/* ANOTHER OBJECT */
	GlobalCollector::Instance()->ingredients.at(2).draw();
	//GlobalCollector::Instance()->ketel.draw();

	glPopMatrix();
	glFlush();
	glutSwapBuffers();

	return 0;
}

int HologramScreen::Setup(int windowWidth, int windowHeight)
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

void HologramScreen::NextItem()
{
	if (currentModel < models.size() - 1)
	{
		currentModel++;
	}
	else
	{
		currentModel = 0;
	}
}

void HologramScreen::PreviousItem()
{
	if (currentModel == 0)
	{
		currentModel = models.size() - 1;
	}
	else
	{
		currentModel--;
	}
}