#pragma once

#ifndef WALL_H_
#define WALL_H_
#define _CRT_SECURE_NO_DEPRECATE

#include "Texture.h"
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

class Wall
{
public:
	Wall();
	Wall(GLint);
	void Wall::draw(void);
	void Wall::move(void);
private:
	GLfloat size = 10;
	GLfloat posX = 0;
	GLfloat posY = 0;
	GLfloat posZ = 0;
	GLuint texture;
	GLuint Wall::loadTexture(const char *);
};


#endif