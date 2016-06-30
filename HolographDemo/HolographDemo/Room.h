#pragma once
#define _CRT_SECURE_NO_DEPRECATE

#include "ObjModel.h"
#include "Texture.h"

#include <iostream>
class Room
{
public:
	Room(GLfloat, GLfloat, GLfloat);
	GLuint Room::loadTexture(const char *);
	void draw();
	GLfloat width;
	GLfloat height;
	GLfloat depth;
private:
	GLuint floorTexture;
	GLuint sideWallTexture;
	GLuint frontWallTexture;
};

