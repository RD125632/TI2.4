#pragma once

#ifndef SYMPTOM_H_
#define SYMPTOM_H_

#include <string>
#include <vector>
#include "SuperObject.h"

class Symptom : public SuperObject
{
public:
	Symptom();
	Symptom(int, std::string, std::string);
	std::string name;
	std::string description;
};



#endif