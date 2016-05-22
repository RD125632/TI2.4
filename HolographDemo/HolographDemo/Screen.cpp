#include "Screen.h"
#include "GL\freeglut.h"

Screen::Screen()
{
	zoom = 1;
	rotateX = 0, rotateY = 0;
}

int Screen::Display()
{

	//Models
	glPolygonMode(GL_FRONT_AND_BACK, mode);

	glPushMatrix();
	if (!isUpsideDown)
	{
		glScalef(zoom, zoom, zoom);
	}
	else
	{
		glScalef(zoom, -zoom, zoom);
	}
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
 