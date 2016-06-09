#pragma once
#define _CRT_SECURE_NO_DEPRECATE

#include "ObjModel.h"
#include "Texture.h"

#include <iostream>
class Room
{
public:
	Room(float size);
	GLuint Room::loadTexture(const char *);
	void draw();
	float size;
private:
	GLuint texture;
};

