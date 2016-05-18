#include "Screen.h"


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
