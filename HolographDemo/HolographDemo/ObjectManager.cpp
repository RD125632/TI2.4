#include "ObjectManager.h"



ObjectManager::ObjectManager()
{
	ketel = new NewKetel("models/ketel/ketel.obj", 0, 0, 0);
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::DrawAll()
{
	for (auto const value : objects)
	{
		value->draw();
	}
}
