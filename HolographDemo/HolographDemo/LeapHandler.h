#include <iostream>
#include <string.h>
#include "Leap.h"

#ifndef SAMPLELISTENER_H
#define SAMPLELISTENER_H

using namespace Leap;

class SampleListener : public Listener
{
	int noPinchTimer = 0;
public:
	virtual void onConnect(const Controller&);
	virtual void onFrame(const Controller&);
	void DrawCube();
	double getX();
	double getY();
	
};
#endif