#include "Room.h"

using namespace std;

Room::Room(GLfloat w, GLfloat h, GLfloat d)
{
	width = w;
	height = h;
	depth = d;
	floorTexture = new Texture("resources/rug.jpg");
	sideWallTexture = new Texture("resources/walls3.png");
	frontWallTexture =  new Texture("resources/walls3.jpg");
	seelingTexture = new Texture("resources/skyseling.jpg");
	 
}

//GLuint Room::loadTexture(const char * imagepath)
//{
//	cout << "->Loading Texture..." << endl;
//	unsigned char header[54];	// Each BMP file begins by a 54-bytes header
//	unsigned int dataPos;		// Position in the file where the actual data begins
//	unsigned int width, height;
//	unsigned int imageSize;		// Size = Width * Height * 3;						
//	unsigned char * data;		// RGB data
//
//								// Open a file and check for flaws
//	FILE * file = fopen(imagepath, "rb");
//	if (!file) { cout << "-> ERROR :: Texture file is missing!" << endl; return 0; }									// If file is not found				: Error
//	if (fread(header, 1, 54, file) != 54) { cout << "-> ERROR :: Texture file is not a BMP!" << endl; return 0; }		// If header is not 54 bytes		: Error
//	if (header[0] != 'B' || header[1] != 'M') { cout << "-> ERROR :: Texture file is not a BMP!" << endl; return 0; }	// If header does not start with BM : Error
//
//																														// Start reading ints from the byte array
//	dataPos = *(int*)&(header[0x0A]);
//	imageSize = *(int*)&(header[0x22]);
//	width = *(int*)&(header[0x12]);
//	height = *(int*)&(header[0x16]);
//
//	if (imageSize == 0)    imageSize = width*height * 3;	// 3 : one byte for each Red, Green and Blue component
//	if (dataPos == 0)      dataPos = 54;					// The BMP header is done that way
//
//
//	data = new unsigned char[imageSize];	// Create a buffer
//	fread(data, 1, imageSize, file);		// Read the actual data from the file into the buffer
//	fclose(file);							// Everything is in memory now, the file can be closed
//
//											//
//											// Create one OpenGL texture
//	GLuint textureID;
//	glGenTextures(1, &textureID);
//
//	// "Bind" the newly created texture : all future texture functions will modify this texture
//	glBindTexture(GL_TEXTURE_2D, textureID);
//
//	// Give the image to OpenGL
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	return textureID;
//}

void Room::draw()
{

	glDisable(GL_LIGHTING);			//turn off lighting, when making the skybox
	glDisable(GL_DEPTH_TEST);       //turn off depth texting
	glTranslated(0, 0, 20);
	glEnable(GL_TEXTURE_2D);

	sideWallTexture->bind();
	//Back face
	glBegin(GL_QUADS);	
	glTexCoord2f(0, 0);		glVertex3f(width / 2, height / 2, depth / 2);
	glTexCoord2f(1, 0);		glVertex3f(-width / 2, height / 2, depth / 2);
	glTexCoord2f(1, 1);		glVertex3f(-width / 2, -height / 2, depth / 2);
	glTexCoord2f(0, 1);		glVertex3f(width / 2, -height / 2, depth / 2);
	glEnd();
	

	frontWallTexture->bind();
	//Left face
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		glVertex3f(-width / 2, height / 2, depth / 2);
	glTexCoord2f(1, 0);		glVertex3f(-width / 2, height / 2, -depth / 2);
	glTexCoord2f(1, 1);		glVertex3f(-width / 2, -height / 2, -depth / 2);
	glTexCoord2f(0, 1);		glVertex3f(-width / 2, -height / 2, depth / 2);
	glEnd();
	

	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	frontWallTexture->bind();
	//Right face
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		glVertex3f(width / 2, height / 2, -depth / 2);
	glTexCoord2f(1, 0);		glVertex3f(width / 2, height / 2, depth / 2);
	glTexCoord2f(1, 1);		glVertex3f(width / 2, -height / 2, depth / 2);
	glTexCoord2f(0, 1);		glVertex3f(width / 2, -height / 2, -depth / 2);
	glEnd();
	



	seelingTexture->bind();
	//Top face
	glBegin(GL_QUADS);                      
	glTexCoord2f(1, 0);		glVertex3f(width / 2, height / 2, depth / 2);
	glTexCoord2f(0, 0);		glVertex3f(-width / 2, height / 2, depth / 2);
	glTexCoord2f(0, 1);		glVertex3f(-width / 2, height / 2, -depth / 2);
	glTexCoord2f(1, 1);		glVertex3f(width / 2, height / 2, -depth / 2);
	glEnd();
	floorTexture->bind();
	glBegin(GL_QUADS);
	//bottom face
	glTexCoord2f(1, 1);		glVertex3f(width / 2, -height / 2, depth / 2);
	glTexCoord2f(0, 1);		glVertex3f(-width / 2, -height / 2, depth / 2);
	glTexCoord2f(0, 0);		glVertex3f(-width / 2, -height / 2, -depth / 2);
	glTexCoord2f(1, 0);		glVertex3f(width / 2, -height / 2, -depth / 2);
	glEnd();

	glTranslated(0, 0, -20);
	glEnable(GL_LIGHTING);  //turn everything back, which we turned on, and turn everything off, which we have turned on.
	glEnable(GL_DEPTH_TEST);
}

