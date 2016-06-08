#pragma once
#include "NewKetel.h"
#include "BillBordParticalEffects.h"
#include "ParticalEmitter.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	NewKetel* ketel;
	// plank,tovenaar,boek

	std::vector<Object *> objects;
	void DrawAll();

};

