#include "Symptom.h"

Symptom::Symptom()
{
}

Symptom::Symptom(int id, std::string newname, std::string desc)
{
	ID = id;
	name = newname;
	description = desc;
}
