#pragma once

#include <vector>
#include <string>

class sound
{
public:
	/**
		Registers a sound in the vector to play it whenever it's needed (one-time declaration of a sound)
		Path of the file will NOT be checked!

		@param  name the name of the sound
				path the path of the file
		@return 1 succeeded
				0 failed
	**/
	static int RegisterSound(std::string, std::string);

	/**
		Plays the requested sound

		@param name the name of the sound
	**/
	static void Playsound(std::string);

private:
	struct SoundStruct
	{
		std::string name, path;
	};
	
	static std::vector<SoundStruct> sounds;

	std::string searchStruct(const std::string);
};