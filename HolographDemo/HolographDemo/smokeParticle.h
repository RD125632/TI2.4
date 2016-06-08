#pragma once
#include "Partical.h"
class smokeParticle : public Partical
{
public:
	smokeParticle(float X, float Y, float Z);
	~smokeParticle();
	void draw();
	static int getID();
	float alpha;
	float red;
	float green;
	float blue;
};

