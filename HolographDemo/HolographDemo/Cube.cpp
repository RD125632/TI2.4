/*-------------------------------------------------------------------------*/
/*				INCLUDES						                           */
/*-------------------------------------------------------------------------*/
#include <GL/freeglut.h>
#include "Cube.h"


/*-------------------------------------------------------------------------*/
/*              Start Code												   */
/*-------------------------------------------------------------------------*/
Cube::Cube()
{
	Init(0.5f);
}
Cube::Cube(float s)
{
	Init(s);

}

void Cube::Init(float s)
{
	color[0].setRGBColor(0.8f, 0.01f, 0.02f);	// FRONT
	color[1].setRGBColor(0.8f, 0.01f, 0.02f);		// BACK
	color[2].setRGBColor(0.8f, 0.01f, 0.02f);		// LEFT
	color[3].setRGBColor(0.8f, 0.01f, 0.02f);		// RIGHT
	color[4].setRGBColor(0.8f, 0.01f, 0.02f);		// TOP
	color[5].setRGBColor(0.8f, 0.01f, 0.02f);		// BOTTOM
}

RGBColor Cube::getColor(Side cSide)
{
	return color[cSide];
}

void Cube::setColor(Side cSide, RGBColor colorValue)
{
	color[cSide] = colorValue;
}

void Cube::draw()
{
		// FRONT
		glBegin(GL_POLYGON);
		glColor3f(color[0].getRed(), color[0].getGreen(), color[0].getBlue());
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(-0.5, 0.5, -0.5);
		glVertex3f(-0.5, -0.5, -0.5);
		glEnd();

		// BACK
		glBegin(GL_POLYGON);
		glColor3f(color[1].getRed(), color[1].getGreen(), color[1].getBlue());
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(-0.5, 0.5, 0.5);
		glVertex3f(-0.5, -0.5, 0.5);
		glEnd();

		// LEFT
		glBegin(GL_POLYGON);
		glColor3f(color[2].getRed(), color[2].getGreen(), color[2].getBlue());
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(-0.5, 0.5, 0.5);
		glVertex3f(-0.5, 0.5, -0.5);
		glVertex3f(-0.5, -0.5, -0.5);
		glEnd();

		// RIGHT
		glBegin(GL_POLYGON);
		glColor3f(color[3].getRed(), color[3].getGreen(), color[3].getBlue());
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glEnd();



		// TOP
		glBegin(GL_POLYGON);
		glColor3f(color[4].getRed(), color[4].getGreen(), color[4].getBlue());
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(-0.5, 0.5, -0.5);
		glVertex3f(-0.5, 0.5, 0.5);
		glEnd();

		// BOTTOM
		glBegin(GL_POLYGON);
		glColor3f(color[5].getRed(), color[5].getGreen(), color[5].getBlue());
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
}

	