#pragma once

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
	bool debugMode;
	float zoom;
	float rotateX, rotateY;
	GLenum mode = GL_FILL;

	std::vector<ObjModel*> models;
};

#endif