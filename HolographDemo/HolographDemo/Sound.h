#pragma once
#include "soloud.h"
#include "soloud_wav.h"
#include <string>
#include <vector>

class SoundEngine
{
public:
	SoundEngine();
	~SoundEngine();
	int registerSound(std::string, std::string);
	void playSound(std::string, bool);

private:
	struct SoundStruct {
		SoLoud::Wav channel;
		std::string name, path; //integer of the playing sound might be needed in this struct as well
	};
	SoLoud::Soloud engine;
	std::vector<SoundStruct> sounds;
};