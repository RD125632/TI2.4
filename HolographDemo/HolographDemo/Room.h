#pragma once

#include "ObjModel.h"
#include "Texture.h"
class Room
{
public:
	Room(float size);
	void draw();
	float size;
	void initSkyBox();
	void killSkyBox();
private:
	Texture *texture;
};