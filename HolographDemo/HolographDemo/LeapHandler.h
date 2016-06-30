#include <iostream>
#include <string.h>
#include "Leap.h"

#ifndef SAMPLELISTENER_H
#define SAMPLELISTENER_H

using namespace Leap;

class SampleListener : public Listener
{
public:
	virtual void onConnect(const Controller&);
	virtual void onFrame(const Controller&);
	//virtual void onDisconnect(const Controller&);
};
#endif