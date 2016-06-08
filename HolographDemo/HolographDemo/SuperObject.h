#pragma once

#ifndef SUPER_H_
#define SUPER_H_

#include <string>
#include <vector>
#include "ObjModel.h"

class SuperObject
{
public:
	int ID;
	GLfloat posX;
	GLfloat posY;
	GLfloat posZ;
	GLfloat rotX;
	GLfloat rotY;
	GLfloat rotZ;
	ObjModel* model;
	void draw()
	{

	};
};



#endif