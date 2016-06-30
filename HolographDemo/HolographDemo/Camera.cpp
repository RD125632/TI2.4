#include "Camera.h"

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
