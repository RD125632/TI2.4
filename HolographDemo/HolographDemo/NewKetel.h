#pragma once
#include "Object.h"
#include <string>

class NewKetel : public Object
{
public:
	NewKetel(std::string, float, float, float);
	NewKetel(std::string, Vec3f*);
	~NewKetel();

private:

};