#pragma once

#ifndef PRESET_SCREEN_H_
#define PRESET_SCREEN_H_

#include <string>

class PresetScreen
{
public:
	RGBColor();
	RGBColor(float r, float g, float b);
	void setRGBColor(float r, float g, float b);

	float getRed() const;
	float getGreen() const;
	float getBlue() const;
private:
	float red;
	float green;
	float blue;
};

#endif