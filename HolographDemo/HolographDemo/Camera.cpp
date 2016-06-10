#include "Camera.h"



Camera::Camera()
{
}

void Camera::MoveToLeft()
{
	if (targetlocation != location3)
	{
		for (int i = 0; i < 3; i++)
		{
			targetlocation[i] = location1[i];
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			targetlocation[i] = location2[i];
		}
	}
}

void Camera::MoveToRight()
{
	if (targetlocation != location1)
	{
		for (int i = 0; i < 3; i++)
		{
			targetlocation[i] = location3[i];
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			targetlocation[i] = location2[i];
		}
	}
}

void Camera::MoveToTarget()
{
	if (targetlocation != currentlocation)
	{
		for (int i = 0; i < 3; i++)
		{
			currentlocation[i] = targetlocation[i];
		}
	}
}


Camera::~Camera()
{
}
