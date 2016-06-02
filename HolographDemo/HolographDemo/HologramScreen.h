#pragma once

#ifndef HOLOGRAMSCREEN_H_
#define HOLOGRAMSCREEN_H_

#include "Screen.h"

class HologramScreen: public Screen
{
public:
	HologramScreen();
	int Display() override;
	int Setup(int,int) override;
	void NextItem();
	void PreviousItem();
	int currentModel;
	bool isUpsideDown = false;
};

#endif