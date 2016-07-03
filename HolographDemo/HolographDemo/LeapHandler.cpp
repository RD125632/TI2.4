/*-------------------------------------------------------------------------*/
/*				INCLUDES						                           */
/*-------------------------------------------------------------------------*/

#include <iostream>
#include <string.h>
#include "Leap.h"
#include <stdio.h>
#include <GL/glut.h>
#include "GlobalCollector.h"
#include <windows.h>
#include <time.h>

using namespace Leap;

/*-------------------------------------------------------------------------*/
/*				Global Variable                                             */
/*-------------------------------------------------------------------------*/

GLfloat xRotated, yRotated, zRotated;
GLfloat deltax, deltay, deltaz = 0;
void draw(void);
double xx;
double yy;
Frame frame;
Ingredient* selectedIngredient = nullptr;
int slIng = -1;

double xxx;
double yyy;
double oldX;

auto circle = 0;
auto swipe = 0;
auto keytap = 0;
auto screentap = 0;
bool drawIt = true;

void SampleListener::onConnect(const Controller& controller) {
	std::cout << "Connected" << std::endl;
	controller.enableGesture(Gesture::TYPE_SWIPE);
	controller.enableGesture(Gesture::TYPE_CIRCLE);
	controller.enableGesture(Gesture::TYPE_KEY_TAP);
	controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
	controller.enableGesture(Gesture::TYPE_INVALID);
}

void swipeGesture() {
	if (GlobalCollector::Instance()->storyScreen.getScreen() == 2 || GlobalCollector::Instance()->storyScreen.getScreen() == 3) {
		time_t newTime;
		time(&newTime);
		if (newTime != GlobalCollector::Instance()->oldTimeForSwipe) {
			GlobalCollector::Instance()->camera.x++;
			GlobalCollector::Instance()->camera.moveCamera();
			if (GlobalCollector::Instance()->camera.x == 3)
			{
				GlobalCollector::Instance()->holoScreen.ShowBook(true);
			}
			else
			{
				GlobalCollector::Instance()->holoScreen.ShowBook(false);
			}
		}
		GlobalCollector::Instance()->oldTimeForSwipe = newTime;
	}
}

void circleGesture() {
	switch (GlobalCollector::Instance()->storyScreen.getScreen())
	{
	case 1:
		GlobalCollector::Instance()->storyScreen.SwitchScreens(2);
		break;
	case 4:
		GlobalCollector::Instance()->storyScreen.SwitchScreens(5);
		break;
	case 5:
		//add functionality
		break;
	default:
		break;
	}
}

void tapGesture() {
	std::cout << "Tap!" << std::endl;
}

void pinching() {
	if (GlobalCollector::Instance()->camera.x == 2) {
		xxx = ((xx * -1) * 10) * 5 - 1;
		yyy = ((yy * -1) * 50) - 13;

		if (selectedIngredient == nullptr) {
			for (unsigned int i = 0; i < GlobalCollector::Instance()->ingredients.size(); i++) {
				if (-yyy + 10 > GlobalCollector::Instance()->ingredients[i].posY - 1.5 && -yyy + 10 < GlobalCollector::Instance()->ingredients[i].posY + 1.5) {
					if (xxx > GlobalCollector::Instance()->ingredients[i].posX - 1.5 && xxx < GlobalCollector::Instance()->ingredients[i].posX + 1.5) {
						oldX = GlobalCollector::Instance()->ingredients[i].posX;
						selectedIngredient = &GlobalCollector::Instance()->ingredients[i];
						slIng = i;
						GlobalCollector::Instance()->soundEngine.Play_Sound("Pickup", false);
					}
				}
			}
		}
	}
}

void readGestures() {
	Leap::SwipeGesture trackedGesture = frame.gesture(Leap::Gesture::TYPE_SWIPE);
	Vector swy = trackedGesture.direction();

	Leap::GestureList gestures = frame.gestures();
	for (Leap::GestureList::const_iterator gl = gestures.begin(); gl != frame.gestures().end(); ++gl)
	{
		switch ((*gl).type()) {
		case Leap::Gesture::TYPE_CIRCLE:
			circle++;
			if (circle >= 10) {
				circleGesture();
				circle = 0;
			}
			break;
		case Leap::Gesture::TYPE_KEY_TAP:
			keytap++;
			if (keytap >= 3) {
				tapGesture();
				keytap = 0;
			}
			break;
		case Leap::Gesture::TYPE_SCREEN_TAP:
			screentap++;
			if (screentap >= 1) {
				tapGesture();
				screentap = 0;
			}
			break;
		case Leap::Gesture::TYPE_SWIPE:
			swipe++;
			if (swipe >= 14) { // was 15
				swipeGesture();
				swipe = 0;
			}
			break;
		default:
			break;
		}

		Leap::SwipeGesture trackedGesture = frame.gesture(Leap::Gesture::TYPE_SWIPE);
		Vector swy = trackedGesture.direction();
	}
}

void SampleListener::onFrame(const Controller& controller) {
	frame = controller.frame();
	auto hands = frame.hands();
	auto pointables = frame.pointables();
	auto fingers = frame.fingers();
	auto tools = frame.tools();
	auto frontHand = hands.frontmost();
	auto handPosition = frontHand.palmPosition();
	xx = double(handPosition.x * 0.005);
	yy = double((handPosition.y * 0.005) - 0.9);

	if (frontHand.pinchStrength() > 0.4) {
		pinching();
		noPinchTimer = 100;
		long tijd = 0;
		drawIt = false;
	}
	else {
		drawIt = true;
		if (slIng >= 0) {
			if (GlobalCollector::Instance()->ingredients[slIng].posY > 6 && selectedIngredient != nullptr) {
				GlobalCollector::Instance()->ingredients[slIng].posY = 15;
				GlobalCollector::Instance()->ingredients[slIng].posX = oldX;
			}
			else if (selectedIngredient != nullptr) {
				while (GlobalCollector::Instance()->ingredients[slIng].posY > -15) {
					GlobalCollector::Instance()->ingredients[slIng].posY -= 0.000005;
				}
				GlobalCollector::Instance()->holoScreen.SetCurrentItem(&GlobalCollector::Instance()->ingredients[slIng]);
			}
		}
		selectedIngredient = nullptr;
		slIng = -1;
	}

	readGestures();
}

void init(void)
{
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glTranslated(0, 0, -13);
}

void Cube() {
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);
	glVertex3f(xx - 0.05, yy - 0.1, 0.0);
	glVertex3f(xx + 0.05, yy - 0.1, 0.0);
	glVertex3f(xx + 0.05, yy + 0.1, 0.0);
	glVertex3f(xx - 0.05, yy + 0.1, 0.0);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void SampleListener::DrawCube(void)
{
	if (drawIt) {
		Cube();
	}

	if (slIng >= 0) {
		GlobalCollector::Instance()->ingredients[slIng].posX = xxx;
		GlobalCollector::Instance()->ingredients[slIng].posY = yyy *-1;
	}
}

void animation(void)
{
	glutPostRedisplay();
}

void reshape(int x, int y)
{
	if (y == 0 || x == 0) return;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);
}

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

double SampleListener::getX() {
	return xx;
}

double SampleListener::getY()
{
	return yy;
}