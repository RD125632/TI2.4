#pragma once

#ifndef SUPER_H_
#define SUPER_H_

#include <string>
#include <vector>
#include "ObjModel.h"
#include <string>

class SuperObject
{
public:
	int ID;
	GLfloat posX = 0;
	GLfloat posY = 0;
	GLfloat posZ = 0;
	GLfloat rotX = 0;
	GLfloat rotY = 0;
	GLfloat rotZ = 0;
	GLfloat scale = 1;
	ObjModel* model;
	std::string type;
	void SetType(std::string);
	std::string GetType() const;
	void draw()
	{
		glTranslatef(posX,posY,posZ);	// Move the object in 3D space
		glRotatef(rotX, 1, 0, 0);		// Rotate X
		glRotatef(rotY, 0, 1, 0);		// Rotate Y
		glRotatef(rotZ, 0, 0, 1);		// Rotate Z
		glScalef(scale, scale, scale);
		model->draw();					// Draw the object
		glTranslatef(-posX, -posY, -posZ);
		glPopMatrix();					// Clear Translate and rotation
	};
};



#endif