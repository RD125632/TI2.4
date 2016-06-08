#include "smokeParticle.h"



static SolidSphere* smoke;
smokeParticle::smokeParticle(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
	red = 0.1f;
	blue = 0.1f;
	green = 0.1f;
	alpha = 1.0f;
	smoke = new SolidSphere(0.1, 20, 20, "resources/smoke2.png");
}

smokeParticle::~smokeParticle()
{
}

void smokeParticle::draw()
{
	glEnable(GL_ALPHA);
	glEnable(GL_COLOR);
	//glDisable(GL_LIGHTING);
	glTranslated(x, y, z);
	glColor4f(red, green, blue, alpha);
	smoke->draw(x, y, z);
	//glColor3f(0.9f, 0.3f, 0.2f);
	glTranslated(-x, -y, -z);
	if (alpha > 0)
	{
		alpha -= 0.001f;
	}

}

int smokeParticle::getID()
{
	return 2;
}
