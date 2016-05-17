#pragma once

#ifndef SCREEN_H_
#define SCREEN_H_

#include <string>
#include <vector>
#include "ObjModel.h"

class Screen
{
public:
	Screen(float, float);
	int Display();
private:
	float width;
	float height;
	std::vector<ObjModel*> models;
};

#endif