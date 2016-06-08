#include "BillBordParticalEffects.h"
#include <ctime>
#include <iostream>
#include <Windows.h>


SYSTEMTIME newTime;
SYSTEMTIME oldTime;
unsigned int timeInterval;
BillBordParticalEffects::BillBordParticalEffects(int X, int Y, int Z, unsigned int Size, char * TexturePath, unsigned int TextureGridWidthAndH)
{
	x = X;
	y = Y;
	z = Z;
	size = Size;
	textureGridWidthAndH = TextureGridWidthAndH;
	
		int width, height, bpp;
		glGenTextures(1, &textureID);
		unsigned char* texture = stbi_load(TexturePath, &width, &height, &bpp, 4);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D,
			0,		//level
			GL_RGBA,		//internal format
			width,		//width
			height,		//height
			0,		//border
			GL_RGBA,		//data format
			GL_UNSIGNED_BYTE,	//data type
			texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //same if the image bigger
		GetSystemTime(&oldTime);
		timeInterval = 500 / (textureGridWidthAndH*textureGridWidthAndH);
	
}

BillBordParticalEffects::~BillBordParticalEffects()
{
}

void BillBordParticalEffects::draw()
{
	GetSystemTime(&newTime);
	float scale = 1.0f / textureGridWidthAndH;
	float aX =  (frameCount%textureGridWidthAndH) * scale;
	float aY =  frameCount/textureGridWidthAndH * scale;
	float bX = aX + scale;
	float bY = aY + scale;
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glColor4f(1, 1, 1, 1);

	glPushMatrix();
	glTranslatef(x, y, z);
	float matrix[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, matrix);

	for (int i = 0; i < 3; i++)
		for (int ii = 0; ii < 3; ii++)
			matrix[i + 4 * ii] = i == ii ? 1 : 0;


	glLoadMatrixf(matrix);


	glBindTexture(GL_TEXTURE_2D, textureID);
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

	if (newTime.wMilliseconds - oldTime.wMilliseconds > timeInterval)
	{
		frameCount++;
		if (frameCount > textureGridWidthAndH*textureGridWidthAndH)
		{
			frameCount = 0;
		}
	}
	glPopMatrix();
}