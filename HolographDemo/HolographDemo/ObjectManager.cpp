#include "ObjectManager.h"



ObjectManager::ObjectManager()
{
	this->ketel = new Ketel(0, 0, 0);
	BillBordParticalEffects *temp = new BillBordParticalEffects(0, 0, 0, 1, "recousces/fireAnimate.png", 4);
	this->effects.push_back(temp);
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::DrawAll()
{
	ketel->draw();
	for (tmp12::WorldObject* effect : effects)
	{
		effect->draw();
	}
}
