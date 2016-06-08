#include "BubblePartical.h"




static SolidSphere *bubble;
BubblePartical::BubblePartical(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
	red = 0.1f;
	blue = 0.1f;
	green = 0.5f;
	alpha = 0.1f;
	bubble = new SolidSphere(0.1, 20, 20,"resources/Bubble.png");
}

BubblePartical::~BubblePartical()
{
}

void BubblePartical::draw()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	//glDisable(GL_TEXTURE_2D);
	glEnable(GL_ALPHA);
	glEnable(GL_COLOR);
	//glDisable(GL_LIGHTING);
	glTranslated(x, y, z);
	glColor4f(red, green, blue, alpha);
	bubble->draw(x, y, z);
	//glColor3f(0.9f, 0.3f, 0.2f);
	glTranslated(-x, -y, -z);
}

int BubblePartical::getID()
{
	return 1;
}
