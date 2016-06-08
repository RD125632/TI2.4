#pragma once
#include "WorldObject.h"
#include"SolidSphere.h"
class Partical : public tmp12::WorldObject
{
public:
	Partical();
	~Partical();
	void draw();
	static int getID();
};

