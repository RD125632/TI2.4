#pragma once
#include "Ketel.h"
#include "BillBordParticalEffects.h"
#include "ParticalEmitter.h"
class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	Ketel *ketel;
	// plank,tovenaar,boek
	std::vector<tmp12::WorldObject*> ingedienten;
	std::vector<tmp12::WorldObject*> effects;
	void DrawAll();

};

