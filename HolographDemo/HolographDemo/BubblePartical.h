#pragma once
#include "Partical.h"

class BubblePartical : public Partical 
{
public:
	BubblePartical(float X, float Y, float Z);
	~BubblePartical();
	void draw();
	float alpha;
	float red;
	float green;
	float blue;
};

