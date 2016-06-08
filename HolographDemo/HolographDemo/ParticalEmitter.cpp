#include "ParticalEmitter.h"




ParticalEmitter::ParticalEmitter(int id, int Intensity, float Interval, float Radius,float X, float Y, float Z)
{
	ID = id;
	intensity = Intensity;
	interval = Interval;
	radius = Radius;
	x = X;
	y = Y;
	z = Z;
	Init();
}

ParticalEmitter::~ParticalEmitter()
{
}



void ParticalEmitter::drawParticals()
{
	update();
	for (Partical *p : particalList)
	{
		p->draw();
	}
}

void ParticalEmitter::update()
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

void ParticalEmitter::Init()
{
	printf("%d,", rand());
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
		}
		
		
	}
	particalList_size = particalList.size();
}

