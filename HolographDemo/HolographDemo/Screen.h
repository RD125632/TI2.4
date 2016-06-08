#pragma once

#ifndef SCREEN_H_
#define SCREEN_H_

#include <string>
#include <vector>
#include "ObjModel.h"

class Screen
{
public:
	Screen();
	int Display();
	void NextItem();
	void PreviousItem();
	int currentModel;
	bool debugMode;
	float zoom;
	bool isUpsideDown = false;
	float rotateX, rotateY;
	GLenum mode = GL_FILL;

	std::vector<ObjModel*> models;
};

#endif