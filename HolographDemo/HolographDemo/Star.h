#pragma once

#include "Partical.h"

class Star : public Partical
{
public:
	Star(float X, float Y, float Z);
	~Star();
	void draw();
	static int getID();
	float alpha = 0;
};
