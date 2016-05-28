#include "Statemanager.h"
#include "Screen.h"
#include "GL\glut.h"

Statemanager::Statemanager(int hologramWindow, int storyWindow)
{
	HologramState = 0;
	StoryState = 0;
	glutSetWindow(hologramWindow);
	Screen screen = Screen();
	//screen.models.push_back(new ObjModel("models/ei/ketel.obj"));
	screen.models.push_back(new ObjModel("models/ketel/ketel.obj"));
	HologramScreens.push_back(screen);

	glutSetWindow(storyWindow);
	Screen screen1 = Screen();
	screen1.models.push_back(new ObjModel("models/ei/ei.obj"));
	StoryScreens.push_back(screen1);
}
