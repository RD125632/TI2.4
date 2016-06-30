#pragma once
#include "Partical.h"
#include "BubblePartical.h"
#include "smokeParticle.h"
#include "Star.h"
#include <vector>
class ParticalEmitter
{
public:
	ParticalEmitter(int ID,int Intensity, float Interval,float Radius, float X, float Y, float Z,bool burstmode, int burstcounter);
	~ParticalEmitter();
	void drawParticals();
	float x;
	float y;
	float z;
	int intensity;
	float interval;
	float radius;
	int counter = 0;
	bool burstMode = false;
	int burstCounter;
private:
	void update();
	std::vector<Partical*> particalList;
	std::vector<Partical*>::size_type particalList_size;
	int ID;
	void Init();
};

