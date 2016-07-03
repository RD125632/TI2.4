#include "Camera.h"
#include <iostream>
#include "GlobalCollector.h"

bool same = false;

Camera::Camera()
{
}

void Camera::MoveToLeft()
{
	if (targetlocation != locations3)
	{
		for (unsigned int i = 0; i < targetlocation.size(); i++)
		{
			targetlocation[i] = locations1[i];
		}
	}
	else
	{
		for (unsigned int i = 0; i < targetlocation.size(); i++)
		{
			targetlocation[i] = locations2[i];
		}
	}
}

void Camera::MoveToRight()
{
	totalSteps = 60;
	amountofsteps = 0;
	same = false;
	if (targetlocation != locations1)
	{
		for (unsigned int i = 0; i < targetlocation.size(); i++)
		{
			steps[i] = (targetlocation[i] - locations3[i]) / totalSteps;
		}
		for (unsigned int i = 0; i < targetlocation.size(); i++)
		{
			targetlocation[i] = locations3[i];
		}
	}
	else
	{
		for (unsigned int i = 0; i < targetlocation.size(); i++)
		{
			steps[i] = (targetlocation[i] - locations2[i]) / totalSteps;
		}
		for (unsigned int i = 0; i < targetlocation.size(); i++)
		{
			targetlocation[i] = locations2[i];
		}
	}
}

void Camera::MoveToTarget()
{
	if (!same)
	{
		same = true;
		for (unsigned int i = 0; i < currentlocation.size(); i++)
		{
			if (currentlocation[i] < targetlocation[i] - steps[i] * 4 || currentlocation[i] > targetlocation[i] + steps[i] * 4)
			{
				same = false;
				currentlocation[i] -= steps[i];
			}
			else
			{
				currentlocation[i] = targetlocation[i];
			}
		}
		if (amountofsteps >= totalSteps)
		{
			for (unsigned int i = 0; i < currentlocation.size(); i++)
			{
				currentlocation[i] = targetlocation[i];
				same = true;
			}
			bool isThree = true;
			for (unsigned int i = 0; i < currentlocation.size(); i++)
			{
				if (currentlocation[i] != locations3[i])
					isThree = false;
			}
			GlobalCollector::Instance()->holoScreen.ShowBook(isThree);
			if (isThree)
				GlobalCollector::Instance()->storyScreen.SwitchScreens(3);
		}
		amountofsteps++;
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
		GlobalCollector::Instance()->storyScreen.SwitchScreens(2);
		break;
	case 3:
		targetlocation = locations3;
		break;
	default:
		break;
	}
	totalSteps = 60;
	amountofsteps = 0;
	same = false;
	for (unsigned int i = 0; i < targetlocation.size(); i++)
	{
		steps[i] = -(targetlocation[i] - currentlocation[i]) / totalSteps;
	}
}
