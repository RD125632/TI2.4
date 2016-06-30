#pragma once
#include <array>

class Camera
{
public:
	std::array<double, 6> locations1 { 0, 20, 15, 0, 20, 20 };
	std::array<double, 6> locations2 { -10,0,-1, 15, 0, 20 };
	std::array<double, 6> locations3 { 10 ,0,-1, 0, 20, 20 };
	std::array<double, 6> currentlocation = locations2;
	std::array<double, 6> targetlocation = locations2;
	Camera();
	void MoveToLeft();
	void MoveToRight();
	void MoveToTarget();
	~Camera();
};
