#include "Screen.h"

Screen::Screen(float w, float h)
{
	width = w;
	height = h;
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
