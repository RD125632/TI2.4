#include "HologramScreen.h"
#include <iostream>

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
		glPushMatrix();
		GlobalCollector::Instance()->book.posX = 0;
		GlobalCollector::Instance()->book.posY = 0;
		GlobalCollector::Instance()->book.rotX += 0.1;
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

		glScalef(1.5, 1.5, 1);
		GlobalCollector::Instance()->ketel.posY = -2;
		GlobalCollector::Instance()->ketel.rotX = 30;
		GlobalCollector::Instance()->ketel.draw();
		glPopMatrix();
		glPushMatrix();
		if (currentObject != nullptr) {
			glScalef(1, 1, 1);

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
}

void HologramScreen::Logic()
{
	if (currentObject != nullptr)
	{
		currentObject->posZ -= 0.1;
		if (currentObject->posZ < GlobalCollector::Instance()->ketel.posZ - 4)
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