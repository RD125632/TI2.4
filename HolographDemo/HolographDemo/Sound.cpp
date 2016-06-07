#include "Sound.h"
#include <vector>

SoundEngine::SoundEngine()
{
	
}

SoundEngine::~SoundEngine()
{
	sounds.clear();
}

int SoundEngine::RegisterSound(std::string name, std::string path)
{
	int i = sounds.size();
	SoundStruct temp;
	temp.name = name;
	temp.path = path;

	sounds.push_back(temp);
	if (i != sounds.size())
		return SUCCES_RETURN;
	else
		return FAILED_RETURN;
}

void SoundEngine::Play_Sound(std::string name, bool repeat)
{
	for (std::vector<SoundStruct>::iterator it = sounds.begin(); it != sounds.end(); ++it) {
		if (it->name == name) {
				PlaySoundA(it->path.c_str(), NULL, SND_ASYNC | SND_FILENAME | (repeat ? SND_LOOP : 0));
		}
	}
}

void SoundEngine::Stop_Sound()
{
	PlaySound(NULL, 0, 0);
}
