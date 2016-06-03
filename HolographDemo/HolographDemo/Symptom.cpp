#include "Symptom.h"

Symptom::Symptom()
{
}

Symptom::Symptom(int ID, std::string newname, std::string desc)
{
	id = ID;
	name = newname;
	description = desc;
}
