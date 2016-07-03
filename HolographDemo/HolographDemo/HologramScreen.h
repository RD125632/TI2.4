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
	static void init();
	static void changeParticel(int, bool, int);
	bool GetShowBook();
	void ShowWizzard(bool);
private:
	SuperObject* currentObject = nullptr;
	bool showBook = false, showWizzard = false;
};

#endif