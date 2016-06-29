#pragma once

#ifndef HOLOGRAMSCREEN_H_
#define HOLOGRAMSCREEN_H_

#include "Screen.h"


class SuperObject;

class HologramScreen : public Screen
{
public:
	HologramScreen();
	int Display() override;
	int Setup(int, int) override;
	int currentModel;
	bool isUpsideDown = false;
	void SetCurrentItem(SuperObject*);
	void Logic();
	void ShowBook(bool);
	void init();
	void changeParticel(int) const;
private:
	SuperObject* currentObject = nullptr;
	bool showBook = false;
};

#endif