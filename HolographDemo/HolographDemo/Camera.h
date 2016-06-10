#pragma once

class Camera
{
public:
	double location1[3] = { 0,0,-1 };
	double location2[3] = { 1,0,-1 };
	double location3[3] = { 2,0,-1 };
	double currentlocation[3] = { 0,0,0 };
	double targetlocation[3] = { 0,0,0 };
	Camera();
	void MoveToLeft();
	void MoveToRight();
	void MoveToTarget();
	~Camera();
};
