#pragma once
#include <array>

class Camera
{
public:
	std::array<double, 6> locations1 { 0, 20, 15, 0, -20, 0 }; //first 3: location, last 3: rotation in 360 degrees
	std::array<double, 6> locations2 { 0, -20, 15, 0, 0, 0 };
	std::array<double, 6> locations3 { 0, 0, -10, 0, 0, 0 };
	std::array<double, 6> currentlocation = locations2;
	std::array<double, 6> targetlocation = locations2;
	Camera();
	void MoveToLeft();
	void MoveToRight();
	void MoveToTarget();
	~Camera();
};
