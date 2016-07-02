#include "Camera.h"
#include <iostream>

Camera::Camera()
{
}

void Camera::MoveToLeft()
{
	if (targetlocation != locations3)
	{
		for (int i = 0; i < targetlocation.size(); i++)
		{
			targetlocation[i] = locations1[i];
		}
	}
	else
	{
		for (int i = 0; i < targetlocation.size(); i++)
		{
			targetlocation[i] = locations2[i];
		}
	}
}

void Camera::MoveToRight()
{
	if (targetlocation != locations1)
	{
		for (int i = 0; i < targetlocation.size(); i++)
		{
			targetlocation[i] = locations3[i];
		}
	}
	else
	{
		for (int i = 0; i < targetlocation.size(); i++)
		{
			targetlocation[i] = locations2[i];
		}
	}
}

void Camera::MoveToTarget()
{
	
	for (int i = 0; i < currentlocation.size(); i++)
	{
		currentlocation[i] = targetlocation[i];
	}
}


Camera::~Camera()
{
}

void Camera::moveCamera()
{
	x = (x % 3) + 1;
	std::cout << x << "\n";
	switch (x)
	{
	case 1:
		targetlocation = locations1;
		break;
	case 2:
		targetlocation = locations2;
		break;
	case 3:
		targetlocation = locations3;
		break;
	default:
		break;
	}
}
