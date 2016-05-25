#include "BubblePartical.h"





BubblePartical::BubblePartical(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
	red = 0.2f;
	blue = 0.4f;
	green = 0.1f;
	alpha = 0.5f;
}

BubblePartical::~BubblePartical()
{
}

void BubblePartical::draw()
{
	glColor4f(red, green, blue, alpha);
	glTranslated(x, y, z);
	glutSolidSphere(0.1, 10, 10);
	glTranslated(-x, -y, -z);
}