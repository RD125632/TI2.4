#include "Star.h"
#include <GL/freeglut.h>
#include "Texture.h"

Texture *texture;
Star::Star(float X, float Y, float Z)
{
	texture = new Texture("resources/star.png");
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
	float size = 0.5f;
	float scale = 0.5f;
	float aX = 0;
	float aY = 0;
	float bX = 1;
	float bY = 1;
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4f(1, 1, 1, 1);

	glPushMatrix();
	glTranslatef(x, y, z);
	//glScaled(1, -1, 1);
	float matrix[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, matrix);

	for (int i = 0; i < 3; i++)
		for (int ii = 0; ii < 3; ii++)
			matrix[i + 4 * ii] = i == ii ? 1 : 0;


	glLoadMatrixf(matrix);


	texture->bind();
	glBegin(GL_QUADS);      //and draw a face
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(bX, aY);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(aX, aY);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(aX, bY);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(bX, bY);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();

	
	glPopMatrix();
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
