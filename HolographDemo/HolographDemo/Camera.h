#pragma once
#include <array>

class Camera
{
public:
	std::array<double, 6> locations1 { 0, 30, -10, 0, 0, 20 };
	std::array<double, 6> locations2 { 1,0,-1, 0, 0, 20 };
	std::array<double, 6> locations3 { 10 ,0,-1, 0, 0, 20 };
	std::array<double, 6> currentlocation { 0,0,0, 0, 0, 0 };
	std::array<double, 6> targetlocation { 0,0,0, 0, 0, 0 };
	Camera();
	void MoveToLeft();
	void MoveToRight();
	void MoveToTarget();
	~Camera();
};
