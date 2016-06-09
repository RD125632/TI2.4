#include "Room.h"



//void Room::draw()
//{
//	glDisable(GL_TEXTURE_2D);
//	glBegin(GL_QUADS);
//	//back face
//	glNormal3f(0, 0, size/2);
//	glVertex3f(size / 2, size / 2, size / 2);
//	glVertex3f(-size / 2, size / 2, size / 2);
//	glVertex3f(-size / 2, -size / 2, size / 2);
//	glVertex3f(size / 2, -size / 2, size / 2);
//	//left face
//	glNormal3f(-size/2, 0, 0);
//	glVertex3f(-size / 2, size / 2, size / 2);
//	glVertex3f(-size / 2, size / 2, -size / 2);
//	glVertex3f(-size / 2, -size / 2, -size / 2);
//	glVertex3f(-size / 2, -size / 2, size / 2);
//	//front face
//	glNormal3f(0, 0, -size/2);
//	glVertex3f(size / 2, size / 2, -size / 2);
//	glVertex3f(-size / 2, size / 2, -size / 2);
//	glVertex3f(-size / 2, -size / 2, -size / 2);
//	glVertex3f(size / 2, -size / 2, -size / 2);
//	//right face
//	glNormal3f(size/2, 0, 0);
//	glVertex3f(size / 2, size / 2, -size / 2);
//	glVertex3f(size / 2, size / 2, size / 2);
//	glVertex3f(size / 2, -size / 2, size / 2);
//	glVertex3f(size / 2, -size / 2, -size / 2);
//	//top face
//	glNormal3f(0, size/2, 0);
//	glVertex3f(size / 2, size / 2, size / 2);
//	glVertex3f(-size / 2, size / 2, size / 2);
//	glVertex3f(-size / 2, size / 2, -size / 2);
//	glVertex3f(size / 2, size / 2, -size / 2);
//	//bottom face
//	glNormal3f(0, -size/2, 0);
//	glVertex3f(size / 2, -size / 2, size / 2);
//	glVertex3f(-size / 2, -size / 2, size / 2);
//	glVertex3f(-size / 2, -size / 2, -size / 2);
//	glVertex3f(size / 2, -size / 2, -size / 2);
//	glEnd();
//}

Room::Room(float size)
{
	
	this->size = size;
	texture = new Texture("resources/woodwalltexture.jpg");
}

void Room::draw()
{
	glColor3f(1, 1, 1);
	bool b1 = glIsEnabled(GL_TEXTURE_2D);     //new, we left the textures turned on, if it was turned on
	glDisable(GL_LIGHTING); //turn off lighting, when making the skybox
	glDisable(GL_DEPTH_TEST);       //turn off depth texting
	glEnable(GL_TEXTURE_2D);        //and turn on texturing
	texture->bind();
	glBegin(GL_QUADS);      //and draw a face
							//back face
	glTexCoord2f(0, 0);      //use the correct texture coordinate
	glVertex3f(size / 2, size / 2, size / 2);       //and a vertex
	glTexCoord2f(1, 0);      //and repeat it...
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, -size / 2, size / 2);
	glEnd();
	
	glBegin(GL_QUADS);
	//left face
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glEnd();
	
	glBegin(GL_QUADS);
	//front face
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
	
	glBegin(GL_QUADS);
	//right face
	glTexCoord2f(0, 0);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();

	glBegin(GL_QUADS);                      //top face
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, size / 2, -size / 2);
	glEnd();
	
	glBegin(GL_QUADS);
	//bottom face
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
	glEnable(GL_LIGHTING);  //turn everything back, which we turned on, and turn everything off, which we have turned on.
	glEnable(GL_DEPTH_TEST);
	if (!b1)
		glDisable(GL_TEXTURE_2D);
}

void Room::initSkyBox()
{
	
}

void Room::killSkyBox()
{
}
