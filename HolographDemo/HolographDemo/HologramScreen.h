#pragma once

#ifndef HOLOGRAMSCREEN_H_
#define HOLOGRAMSCREEN_H_

#include "Screen.h"
#include "SuperObject.h"
#include "GlobalCollector.h"

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

private:
	SuperObject* currentObject = nullptr;
	bool showBook = false;
};

#endif