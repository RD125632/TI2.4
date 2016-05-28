#include "Screen.h"
#include "GL\freeglut.h"

Screen::Screen()
{
	zoom = 1;
	rotateX = 0, rotateY = 0;
	currentModel = 0;
	debugMode = false;
}

int Screen::Display()
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

void Screen::NextItem()
{
	if (currentModel < models.size())
	{
		currentModel++;
	}
	else
	{
		currentModel = 0;
	}
}

void Screen::PreviousItem()
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