#include <iostream>
#include <string.h>
#include "Leap.h"
#include <stdio.h> 
#include <GL/glut.h>

using namespace Leap;

GLfloat xRotated, yRotated, zRotated;
GLfloat deltax, deltay, deltaz = 0;
void draw(void);
double xx;
double yy;
Frame frame;

auto circle = 0;
auto swipe = 0;
auto keytap = 0;
auto screentap = 0;

class SampleListener : public Listener {
public:
	virtual void onConnect(const Controller&);
	virtual void onFrame(const Controller&);
};

void SampleListener::onConnect(const Controller& controller) {
	std::cout << "Connected" << std::endl;
	controller.enableGesture(Gesture::TYPE_SWIPE);
	controller.enableGesture(Gesture::TYPE_CIRCLE);
	controller.enableGesture(Gesture::TYPE_KEY_TAP);
	controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
	controller.enableGesture(Gesture::TYPE_INVALID);
}

void swipeGesture() {
	std::cout << "Swipemovement!" << std::endl;
}

void circleGesture() {
	std::cout << "Circlemovement!" << std::endl;
}

void tapGesture() {
	std::cout << "Tap!" << std::endl;
}

void pinching() {
	std::cout << "Pinching!" << std::endl;
}

void readGestures() {

	Leap::GestureList gestures = frame.gestures();
	for (Leap::GestureList::const_iterator gl = gestures.begin(); gl != frame.gestures().end(); gl++)
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
			if (swipe >= 30) {
				swipeGesture();
				swipe = 0;
			}
			break;
		default:
			break;
		}

		Leap::SwipeGesture trackedGesture = frame.gesture(Leap::Gesture::TYPE_SWIPE);

		Vector swy = trackedGesture.direction();

		if (swy.x > 0) {
			std::cout << "Right!" << std::endl;
		}
		else {
			std::cout << "Left!" << std::endl;
		}


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
	xx = double(handPosition.x*0.05);
	yy = double((handPosition.y - 300) / 50);

	if (frontHand.pinchStrength() >0.8) {
		pinching();
	}

	// x en y hebben standaard andere waarden, maar voor ons voorbeeldframe hebben we die aangepast hierboven, als je die weer terug wilt zetten moet je die regels even weghalen, want nu zijn die maximaal 8 volgens mij.


	//std::cout << "X: " << int(handPosition.x) << " Y: " << int(handPosition.y) << " Z: " << int(handPosition.z) << " Pinch: " << frontHand.pinchStrength() << std::endl;
	readGestures();
}

void init(void)
{
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_MODELVIEW);
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glTranslated(0, 0, -13);
}

void DrawCube(void)
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(xx - 0.1, yy - 0.1, 0.0);
	glVertex3f(xx + 0.1, yy - 0.1, 0.0);
	glVertex3f(xx + 0.1, yy + 0.1, 0.0);
	glVertex3f(xx - 0.1, yy + 0.1, 0.0);
	glEnd();            // End Drawing The Cube
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
	DrawCube();
	glutSwapBuffers();
}

