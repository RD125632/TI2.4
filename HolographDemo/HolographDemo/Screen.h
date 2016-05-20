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
	float zoom;
	bool isUpsideDown = false;
	float rotateX, rotateY;

	std::vector<ObjModel*> models;
};

#endif