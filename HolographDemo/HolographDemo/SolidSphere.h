#pragma once
#include "WorldObject.h"
class SolidSphere
{
public:
	SolidSphere(float radius, unsigned int rings, unsigned int sectors,char* path);
	SolidSphere(float radius, unsigned int rings, unsigned int sectors, char* path,int texturesxy);
	void draw(GLfloat x, GLfloat y, GLfloat z);
		~SolidSphere();
		void init();
private:
	char* TexturePath;
	bool animated;
	int TexturesGrid;
};

