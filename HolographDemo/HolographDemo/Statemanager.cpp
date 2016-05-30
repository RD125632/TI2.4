#include "Statemanager.h"
#include "Screen.h"
#include "GL\glut.h"

Statemanager::Statemanager(int hologramWindow, int storyWindow)
{
	HologramState = 0;
	StoryState = 0;
	glutSetWindow(hologramWindow);
	Screen screen = Screen();
	screen.models.push_back(new ObjModel("models/slimeball/slimeball.obj"));
	screen.models.push_back(new ObjModel("models/ketel/ketel.obj"));
	screen.models.push_back(new ObjModel("models/ei/ei.obj"));
	screen.models.push_back(new ObjModel("models/bloemetje/PrimroseP.obj"));
	screen.models.push_back(new ObjModel("models/book/spellbook.obj"));
	screen.models.push_back(new ObjModel("models/bread/bread.obj"));
	screen.models.push_back(new ObjModel("models/car/honda_jazz.obj"));
	screen.models.push_back(new ObjModel("models/cheese/cheese.obj"));
	screen.models.push_back(new ObjModel("models/cube/cube-textures.obj"));
	screen.models.push_back(new ObjModel("models/diamond/diamond.obj"));
	screen.models.push_back(new ObjModel("models/eye/eye.obj"));
	screen.models.push_back(new ObjModel("models/flower/flower.obj"));
	screen.models.push_back(new ObjModel("models/kies/kies.obj"));
	screen.models.push_back(new ObjModel("models/normalstuff/normaltest.obj"));
	screen.models.push_back(new ObjModel("models/pearl/pearl.obj"));
	screen.models.push_back(new ObjModel("models/plank/plank.obj"));
	screen.models.push_back(new ObjModel("models/polspoon/polspoon.obj"));
	screen.models.push_back(new ObjModel("models/ship/shipA_OBJ.obj"));
	//screen.models.push_back(new ObjModel("models/shroom/Magic Mushroom.obj"));
	screen.models.push_back(new ObjModel("models/slimeball/slimeball.obj"));
	//screen.models.push_back(new ObjModel("models/office/Office.obj"));
	HologramScreens.push_back(screen);

	glutSetWindow(storyWindow);
	Screen screen1 = Screen();
	screen1.models.push_back(new ObjModel("models/ei/ei.obj"));
	StoryScreens.push_back(screen1);
}
