#pragma once

#ifndef SYMPTOM_H_
#define SYMPTOM_H_

#include <string>
#include <vector>

class Symptom
{
public:
	Symptom();
	Symptom(int, std::string, std::string);
	int id;
	std::string name;
	std::string description;
};



#endif