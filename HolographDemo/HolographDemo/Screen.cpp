#include "Screen.h"
#include "GL\freeglut.h"

Screen::Screen()
{
}

int Screen::Display()
{
	//Models
	for (auto m : models)
	{
		m->draw();
	}

	return 0;
}
