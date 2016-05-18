#include "Statemanager.h"
#include "Screen.h"

Statemanager::Statemanager()
{
	HologramState = 0;
	StoryState = 0;
	Screen screen = Screen();
	screen.models.push_back(new ObjModel("models/eye/eye.obj"));
	HologramScreens.push_back(screen);

	Screen screen1 = Screen();
	screen1.models.push_back(new ObjModel("models/ei/ei.obj"));
	StoryScreens.push_back(screen1);
}
