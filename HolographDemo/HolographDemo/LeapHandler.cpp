#include "LeapHandler.h"

void SampleListener::onConnect(const Controller& controller) {
	std::cout << "Connected" << std::endl;
	controller.enableGesture(Gesture::TYPE_SWIPE);
	controller.enableGesture(Gesture::TYPE_CIRCLE);
	controller.enableGesture(Gesture::TYPE_KEY_TAP);
	controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
	controller.enableGesture(Gesture::TYPE_INVALID);
}

void SampleListener::onFrame(const Controller& controller)
{
	const Frame frame = controller.frame();

	auto hands = frame.hands();
	auto firstHand = hands.frontmost();
	auto position = firstHand.palmPosition();

	std::cout << "x: " << int(position.x) << " y: " << int(position.y) << " z: " << int(position.z) << std::endl;
}

void SampleListener::onDisconnect(const Controller&)
{
	std::cout << "leap disconnected" << std::endl;
	
}
