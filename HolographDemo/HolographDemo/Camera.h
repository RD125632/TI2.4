#pragma once
#include <array>

class Camera
{
public:

	std::array<double, 6> locations1{ 10, 0, -1, 15, 0, 20 };
	std::array<double, 6> locations2{ 0, 20, 15, 0, 20, 20 };
	std::array<double, 6> locations3{ -10 , 0, -1, -15, 0, 20 };
	std::array<double, 6> currentlocation = locations1;
	std::array<double, 6> targetlocation = locations1;
	std::array<double, 6> steps{ 0,0,0,0,0,0 };

	Camera();
	void MoveToLeft();
	void MoveToRight();
	void MoveToTarget();
	~Camera();
	void moveCamera();
	int x = 1;
};
