#pragma once
#include "Partical.h"
#include "BubblePartical.h"
#include "smokeParticle.h"
#include <vector>
class ParticalEmitter
{
public:
	ParticalEmitter(int ID,int Intensity, float Interval,float Radius, float X, float Y, float Z);
	~ParticalEmitter();
	void drawParticals();
	float x;
	float y;
	float z;
	int intensity;
	float interval;
	float radius;
	int counter = 0;
private:
	void update();
	std::vector<Partical*> particalList;
	std::vector<Partical*>::size_type particalList_size;
	int ID;
	void Init();
};

