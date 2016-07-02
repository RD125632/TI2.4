#include "ParticalEmitter.h"




ParticalEmitter::ParticalEmitter(int id, int Intensity, float Interval, float Radius,float X, float Y, float Z,bool burstmode,int burstcounter)
{
	ID = id;
	intensity = Intensity;
	interval = Interval;
	radius = Radius;
	x = X;
	y = Y;
	z = Z;
	burstMode = burstmode;
	burstCounter = burstcounter;
	Init();
}

ParticalEmitter::~ParticalEmitter()
{
}



void ParticalEmitter::drawParticals()
{
	if (particalList_size > 0)
	{
		update();
		for (Partical *p : particalList)
		{
			p->draw();
		}
	}
}

void ParticalEmitter::update()
{
	if (burstMode)
	{
		for (unsigned int i = 0; i < particalList_size; i++)
		{
			if (particalList[i]->y >= 10)
			{
				particalList.erase(particalList.begin() + i);
				particalList_size--;
			}
			else
			{
				particalList[i]->y += 0.01f;;
			}

		}
		counter++;
		if (counter == 30 && burstCounter > 0)
		{
			Init();
			counter = 0;
			burstCounter--;
		}
	}
	else
	{
		for (int i = 0; i < particalList_size; i++)
		{
			if (particalList[i]->y >= 10)
			{
				particalList.erase(particalList.begin() + i);
				particalList_size--;
			}
			else
			{
				particalList[i]->y += 0.01f;;
			}

		}
		counter++;
		if (counter == 30)
		{
			Init();
			counter = 0;
		}
	}

}

void ParticalEmitter::Init()
{
	for (int i = intensity; i > 0; i--)
	{
		switch (ID)
		{
		case 1:
			particalList.push_back(new BubblePartical(x + radius*rand() / 30000, y + radius * rand() / 30000, z + radius * rand() / 30000));
			break;
		case 2:
			particalList.push_back(new smokeParticle(x + radius*rand() / 30000, y + radius * rand() / 30000, z + radius * rand() / 30000));
			break;
		case 3:
			particalList.push_back(new Star(x + radius*rand() / 30000, y + radius * rand() / 30000, z + radius * rand() / 30000));
			break;
		}
		
		
	}
	particalList_size = particalList.size();
}

