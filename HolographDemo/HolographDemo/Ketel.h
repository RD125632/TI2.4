
/*
Obsolete!!
*/

#pragma once
#include "WorldObject.h"
#include "ObjModel.h"
class Ketel:public tmp12::WorldObject
{
public:

	Ketel(float x, float y, float z);
	~Ketel();
	void draw();
private:
	ObjModel *model;
};

