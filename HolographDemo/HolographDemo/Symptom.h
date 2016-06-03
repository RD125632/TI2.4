#pragma once

#ifndef SYMPTOM_H_
#define SYMPTOM_H_

#include <string>
#include <vector>

class Symptom
{
public:
	Symptom();
	Symptom(std::string, std::string);
	std::string name;
	std::string description;
};



#endif