#include "HologramScreen.h"
#include <iostream>

#include "SuperObject.h"
#include "GlobalCollector.h"
#include "WorldObject.h"
#include "BillBordParticalEffects.h"
#include "ParticalEmitter.h"

BillBordParticalEffects *fire;
ParticalEmitter *particalEmitter;

HologramScreen::HologramScreen() : Screen()
{
	currentModel = 0;
}

int HologramScreen::Display()
{
	//Models
	glPolygonMode(GL_FRONT_AND_BACK, mode);
	if (showBook)
	{
		GLfloat position[4] = { GlobalCollector::Instance()->book.posX, GlobalCollector::Instance()->book.posY + 3, GlobalCollector::Instance()->book.posZ, 1 };
		glLightfv(GL_LIGHT0, GL_POSITION, position);
		glPushMatrix();
		
		GlobalCollector::Instance()->book.posY = float(cos(GlobalCollector::Instance()->book.rotY * 0.05));
		
		GlobalCollector::Instance()->book.rotY += 0.05f;
		GlobalCollector::Instance()->book.draw();
		glPopMatrix();
	}
	else {
		glPushMatrix();
		if (!isUpsideDown)
		{
			glScalef(-1, 1, 1);
		}
		else
		{
			glScalef(-1, -1, 1);
		}

		GLfloat position[4] = { GlobalCollector::Instance()->ketel.posX, GlobalCollector::Instance()->ketel.posY, GlobalCollector::Instance()->ketel.posZ, 0 };
		glLightfv(GL_LIGHT0, GL_POSITION, position); //light misschien ergens anders

		glScalef(1.5, 1.5, 1.5);
		
		GlobalCollector::Instance()->ketel.draw();
		glDisable(GL_LIGHTING);
		fire->draw();
		particalEmitter->drawParticals();
		glEnable(GL_LIGHTING);
		

		glPopMatrix();

		glPushMatrix();
		if (currentObject != nullptr) {
			glScalef(0.5, 0.5, 0.5);

			// nog verdr uitwerken

			currentObject->draw();
		}
		glPopMatrix();
	}
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

	gluPerspective(90, float(windowWidth / windowHeight), 0.1f, 200);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 1, -zoom + 8,
		0, 0, 0,
		0, 1, 0);

	return 1;
}

void HologramScreen::SetCurrentItem(SuperObject* obj)
{
	this->currentObject = obj;
	currentObject->posX = 0;
	currentObject->posZ = 0;
	currentObject->posY = 10;
}

void HologramScreen::Logic()
{
	if (currentObject != nullptr)
	{
		currentObject->posY -= 0.03f;
		if (currentObject->posY < GlobalCollector::Instance()->ketel.posY - 3)
		{
			GlobalCollector::Instance()->ketel.AddIngredient(currentObject);
			currentObject = nullptr;
		}
	}
}

void HologramScreen::ShowBook(bool show)
{
	showBook = show;
}

void HologramScreen::init()
{
	GlobalCollector::Instance()->book.rotX = 10;
	GlobalCollector::Instance()->book.posX = 0;
	GlobalCollector::Instance()->ketel.posY = -2;
	GlobalCollector::Instance()->ketel.rotX = 30;
	fire = new BillBordParticalEffects(GlobalCollector::Instance()->ketel.posX, GlobalCollector::Instance()->ketel.posY -10, GlobalCollector::Instance()->ketel.posZ+5, 10, "resources/fireAnimate.png", 4);
	particalEmitter = new ParticalEmitter(1, 5, 1, 0.5f, GlobalCollector::Instance()->ketel.posX, GlobalCollector::Instance()->ketel.posY, GlobalCollector::Instance()->ketel.posZ);
	
}
