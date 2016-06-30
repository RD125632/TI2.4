#pragma once

#ifndef SUPER_H_
#define SUPER_H_

#include <string>
#include <vector>
#include "ObjModel.h"

enum IngredientType { none, cheese, eye, slimeball }; //moet verder aangevuld worden (none is voor de niet-ingredienten). kan gebruikt worden voor de ingredienten in de lijst in de ketel (dat zijn namelijk alleen superobjecten)

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
	ObjModel* model;
	IngredientType type;
	void SetType(IngredientType);
	IngredientType GetType() const;
	void draw()
	{
		glTranslatef(posX, posY, posZ);	// Move the object in 3D space
		glRotatef(rotX, 1, 0, 0);		// Rotate X
		glRotatef(rotY, 0, 1, 0);		// Rotate Y
		glRotatef(rotZ, 0, 0, 1);		// Rotate Z
		model->draw();					// Draw the object
		glPopMatrix();					// Clear Translate and rotation
		glDisable(GL_TEXTURE_2D);
	} //waarom is er code in de .h file???
};

#endif