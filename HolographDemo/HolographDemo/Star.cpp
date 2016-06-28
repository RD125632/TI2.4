#include "Star.h"
#include <GL/freeglut.h>

static SolidSphere* star;

Star::Star(float X, float Y, float Z)
{
	star = new SolidSphere(0.5, 20, 20, "resources/star.png");
	alpha = 1;
	x = X;
	y = Y;
	z = Z;
}

Star::~Star()
{
}

void Star::draw()
{
	glEnable(GL_ALPHA);
	glEnable(GL_COLOR);
	glTranslated(x, y, z);
	glColor4f(1.0, 1.0, 0.5, alpha);
	star->draw(x, y, z);
	glTranslated(-x, -y, -z);
	if (alpha > 0)
	{
		alpha -= 0.01f;
	}
}

int Star::getID()
{
	return 3; //moet naar de juiste int worden gezet
}
