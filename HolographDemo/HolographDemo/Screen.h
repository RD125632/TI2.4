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

	std::vector<ObjModel*> models;
};

#endif