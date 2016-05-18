#pragma once
#include <GL\freeglut.h>
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include "stb_image.h"

namespace tmp12 {
	class WorldObject
	{
	public:
		WorldObject();
		~WorldObject();
		virtual bool pointInObject(float x, float y, float z);
		virtual bool cubeInObject(float Xmin, float Xmax, float Ymin, float Ymax, float Zmin, float Zmax);
		virtual void draw()=0;
		float x;
		float y;
		float z;
		float pitch;
		float yaw;
		bool gravityEffected;
	/*	float getX();
		float getY();
		float getZ();
		float getYaw();
		float getPitch();*/

	protected:
		
	};
}
