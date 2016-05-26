#include "Sound.h"
#include <thread>
#include <future>

int sound::RegisterSound(std::string name, std::string path)
{
	int i = sounds.size();
	SoundStruct temp;
	temp.name = name;
	temp.path = path;
	sounds.push_back(temp);

	if (i == sounds.size())
		return 0;
	else
		return 1;
}


std::string sound::searchStruct(const std::string name)
{
	for (std::vector<SoundStruct>::iterator it = sounds.begin(); it != sounds.end(); ++it)
		if (it->name == name)
			return it->path;
}

void sound::Playsound(const std::string name)
{
	auto future = std::async(searchStruct, name);
	PlaySound(TEXT(future.get()), NULL, SND_FILENAME | SND_ASYNC);
}

