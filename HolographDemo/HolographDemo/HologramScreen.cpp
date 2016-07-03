#include "HologramScreen.h"
#include <iostream>

#include "SuperObject.h"
#include "GlobalCollector.h"
#include "WorldObject.h"
#include "BillBordParticalEffects.h"
#include "ParticalEmitter.h"

BillBordParticalEffects* fire, *fire2;
ParticalEmitter* particalEmitter;

HologramScreen::HologramScreen() : Screen()
{
	currentModel = 0;
}

int HologramScreen::Display()
{
	//Models
	glPolygonMode(GL_FRONT_AND_BACK, mode);
	glDisable(GL_BLEND);

	glPushMatrix();
	if(showWizzard)
	{
		glPushMatrix();
		glScalef(2, 2, 2);
		GlobalCollector::Instance()->holoWizzard.draw();
		glScalef(1, 1, 1);
		glPopMatrix();
	}
	else if (showBook)
	{
		glPushMatrix();
		glScalef(2, 2, 2);
		GlobalCollector::Instance()->book.posY = 1;
		GlobalCollector::Instance()->book.posY += float(cos(GlobalCollector::Instance()->book.rotY * 0.05));

		GlobalCollector::Instance()->book.rotY += 0.05f;
		GlobalCollector::Instance()->book.draw();
		glScalef(1, 1, 1);
		glPopMatrix();
	}
	else
	{
		glPushMatrix();
		glScalef(2, 2, 2);

		GlobalCollector::Instance()->ketel.draw();
		glScalef(1, 1, 1);

		glDisable(GL_LIGHTING);
		fire->draw();
		fire2->draw();

		if (particalEmitter != nullptr)
		{
			glScalef(1.5, 1.5, 1.5);
			particalEmitter->drawParticals();
			glScalef(1, 1, 1);
		}
		glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);

		glPopMatrix();

		glPushMatrix();
		if (currentObject != nullptr)
		{
			glScalef(0.75, 0.75, 0.75);
			currentObject->draw();
		}
		glPopMatrix();

		GlobalCollector::Instance()->ketel.posY = float(cos(GlobalCollector::Instance()->ketel.rotY * 0.1)) / 5 - 2;
		GlobalCollector::Instance()->ketel.rotY += 0.01f;
	}
	glPopMatrix();
	glFlush();
	glutSwapBuffers();

	return 0;
}

int HologramScreen::Setup(int windowWidth, int windowHeight)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.00392156862f, 0.00784313725f, 0.01176470588f, 1.0f);

	glViewport(0, 0, windowWidth, windowHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (isUpsideDown)
		glScalef(1, -1, 1);

	gluPerspective(90, float(windowWidth) / windowHeight, 0.1f, 200);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 2, 10,
	          0, 0, 0,
	          0, 1, 0);

	return 1;
}

void HologramScreen::SetCurrentItem(SuperObject* obj)
{
	this->currentObject = obj;
	currentObject->posX = 0;
	currentObject->posZ = 0;
	currentObject->posY = 15;
}

void HologramScreen::Logic()
{
	if (currentObject != nullptr)
	{
		currentObject->posY -= 0.05f;
		if (currentObject->posY < GlobalCollector::Instance()->ketel.posY - 3)
		{
			GlobalCollector::Instance()->ketel.AddIngredient(currentObject->type);
			GlobalCollector::Instance()->soundEngine.Play_Sound("Splash", false);
			changeParticel(1, true, 10);
			currentObject->posY = -300;
			currentObject = nullptr;
		}
	}
}

void HologramScreen::ShowBook(bool show)
{
	showBook = show;
	if(show)
	{
		GlobalCollector::Instance()->soundEngine.Play_Sound("Book", true);
	} else
	{
		GlobalCollector::Instance()->soundEngine.Stop_Sound();
	}
}

void HologramScreen::init()
{
	GlobalCollector::Instance()->book.rotX = 10;
	GlobalCollector::Instance()->book.rotY = 180;
	GlobalCollector::Instance()->book.posX = 0;
	GlobalCollector::Instance()->ketel.posY = -1;
	GlobalCollector::Instance()->ketel.rotX = 15;
	GlobalCollector::Instance()->holoWizzard.rotX = -90;
	GlobalCollector::Instance()->holoWizzard.posX = 0;
	GlobalCollector::Instance()->holoWizzard.posY = -1;
	GlobalCollector::Instance()->holoWizzard.posZ = -5;
	fire = new BillBordParticalEffects(GlobalCollector::Instance()->ketel.posX+3, GlobalCollector::Instance()->ketel.posY - 6, GlobalCollector::Instance()->ketel.posZ + 5, 10, "resources/fireAnimate.png", 4);
	fire2 = new BillBordParticalEffects(GlobalCollector::Instance()->ketel.posX-3, GlobalCollector::Instance()->ketel.posY - 6, GlobalCollector::Instance()->ketel.posZ + 5, 10, "resources/fireAnimate.png", 4);
}

void HologramScreen::changeParticel(int part, bool burst, int amount)
{
	particalEmitter = new ParticalEmitter(part, 5, 1, 1.0f, GlobalCollector::Instance()->ketel.posX - 0.75f, GlobalCollector::Instance()->ketel.posY, GlobalCollector::Instance()->ketel.posZ, burst, amount);
}

bool HologramScreen::GetShowBook()
{
	return showBook;
}

void HologramScreen::ShowWizzard(bool show)
{
	showWizzard = show;
}
