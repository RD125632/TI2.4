#pragma once

#include <string>
#include <Windows.h>
#include <vector>

#ifndef SOUND_ENGINE_CLASS
#define SOUND_ENGINE_CLASS

#define FAILED_RETURN 0
#define SUCCES_RETURN 1

class SoundEngine
{
	public:
		SoundEngine();
		~SoundEngine();
		int RegisterSound(std::string, std::string);
		void Play_Sound(std::string, bool);

	private:
		struct SoundStruct
		{
			std::string name, path;
		};
		std::vector<SoundStruct> sounds;
};


#endif