#pragma once
#include "WorldObject.h"
#ifndef SCREEN_H_
#define SCREEN_H_

#include <string>
#include <vector>
#include "ObjModel.h"
#include "GL\freeglut.h"

class Screen
{
public:
	Screen();
	virtual int Display() = 0;
	virtual int Setup(int,int) = 0;
	bool debugMode;
	float zoom;
	float rotateX, rotateY;
	GLenum mode = GL_FILL;

	std::vector<tmp12::WorldObject *> objects;
};

#endif