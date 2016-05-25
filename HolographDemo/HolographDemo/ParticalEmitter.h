#pragma once
#include "Partical.h"
#include "BubblePartical.h"
#include <vector>
class ParticalEmitter
{
public:
	ParticalEmitter(int Intensity, float Interval, float X, float Y, float Z);
	~ParticalEmitter();
	void setPartical(Partical p,int Intensity,float Interval, float X, float Y, float Z);
	void drawParticals();
	float x;
	float y;
	float z;
	int intensity;
	float interval;
	int counter = 0;
private:
	void update();
	std::vector<Partical*> particalList;
	std::vector<Partical*>::size_type particalList_size;
	Partical BaseParticel;
	void Init();
};

