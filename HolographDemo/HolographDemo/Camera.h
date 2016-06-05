#pragma once

class Camera
{
public:
	double location1[3] = { 1,1,1 };
	double location2[3] = { 1,1,1 };
	double location3[3] = { 1,1,1 };
	double currentlocation[3] = { 0,0,-2 };
	Camera();
	~Camera();
};
