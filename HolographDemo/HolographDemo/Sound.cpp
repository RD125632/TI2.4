#include "Sound.h"
#include "soloud.h"
#include <string>

SoundEngine::SoundEngine()
{
	engine.init();
}

SoundEngine::~SoundEngine()
{
	sounds.clear();
	engine.deinit();
}

int SoundEngine::registerSound(std::string name, std::string path)
{
	int i = sounds.size();
	SoLoud::Wav channel;
	SoundStruct temp;

	temp.name = name;
	temp.path = path;
	channel.load(path.c_str());
	temp.channel = channel;
	
	sounds.push_back(temp);
	if (i == sounds.size())
		return 0;
	else
		return 1;
}

void SoundEngine::playSound(std::string name, bool loop)
{
	for(std::vector<SoundStruct>::iterator it = sounds.begin(); it != sounds.end(); ++it)
		if (it->name == name) {
			it->soundnr = engine.play(it->channel);
			engine.setLooping(it->soundnr, loop);
		}
}

void SoundEngine::stopLooping(std::string name)
{
	for (std::vector<SoundStruct>::iterator it = sounds.begin(); it != sounds.end(); ++it)
		if (it->name == name) {
			engine.setLooping(it->soundnr, false);
		}
}

