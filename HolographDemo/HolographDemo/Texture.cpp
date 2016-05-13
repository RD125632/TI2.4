#define STB_IMAGE_IMPLEMENTATION

#include "Texture.h"
#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/glu.h>
#include "stb_image.h"

Texture::Texture(const std::string & filename)
{
	int width, height, bpp;
	glGenTextures(1, &textureID);
	unsigned char* texture = stbi_load("resources/terainMap.png", &width, &height, &bpp, 4);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D,
		0,		//level
		GL_RGBA,		//internal format
		width,		//width
		height,		//height
		0,		//border
		GL_RGBA,		//data format
		GL_UNSIGNED_BYTE,	//data type
		texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //same if the image bigger
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, textureID);
}
