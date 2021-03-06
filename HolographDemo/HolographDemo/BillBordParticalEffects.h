#pragma once
#include "WorldObject.h"

class BillBordParticalEffects : public tmp12::WorldObject  
{
public:
	BillBordParticalEffects(int X,int Y, int Z, int Size, char* TexturePath,unsigned int TextureGridWidthAndH);
	~BillBordParticalEffects();
	void draw();
	int size;
private:
	unsigned int textureID;
	unsigned int textureGridWidthAndH;
	unsigned int frameCount = 0;
	SYSTEMTIME newTime;
	SYSTEMTIME oldTime;
	unsigned int timeInterval;
};

