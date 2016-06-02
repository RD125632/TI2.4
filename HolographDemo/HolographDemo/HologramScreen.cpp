#include "HologramScreen.h"
#include <iostream>

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
		glScalef(-zoom, zoom, zoom);
	}
	else
	{
		glScalef(-zoom, -zoom, zoom);
	}
	glRotatef(rotateX, 1, 0, 0);
	glRotatef(rotateY, 0, 1, 0);
	if (debugMode)
	{
		models[currentModel]->draw();
	}
	else
	{
		for (auto m : models)
		{
			m->draw();
		}
	}
	glPopMatrix();
	glFlush();
	glutSwapBuffers();

	return 0;
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