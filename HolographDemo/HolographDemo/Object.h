#pragma once
#include <string>
#include "ObjModel.h"

class Object : public ObjModel {
public:
	Object(float, float, float, std::string);
	Object(Vec3f *, std::string);
	void Draw();
	Vec3f* getLocation();
	void setLocation(Vec3f*);
	
private:
	Vec3f *location;
};