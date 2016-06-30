#pragma once

#ifndef SUPER_H_
#define SUPER_H_

#include <string>
#include <vector>
#include "ObjModel.h"
#include <map>

enum IngredientType { none, cheese, eye, slimeball, baksteen, bloem, bot, brood, car, diamont, egg, bloempot, tand, parel, boot, paddestoel}; //moet verder aangevuld worden (none is voor de niet-ingredienten). kan gebruikt worden voor de ingredienten in de lijst in de ketel (dat zijn namelijk alleen superobjecten


class SuperObject
{
public:
	SuperObject();
	int ID;
	GLfloat posX = 0;
	GLfloat posY = 0;
	GLfloat posZ = 0;
	GLfloat rotX = 0;
	GLfloat rotY = 0;
	GLfloat rotZ = 0;
	GLfloat scale = 1;
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
		glScalef(scale, scale, scale);
		model->draw();	
		glTranslatef(-posX, -posY, -posZ);// Draw the object
		glPopMatrix();					// Clear Translate and rotation
		glDisable(GL_TEXTURE_2D);
	}


};

template <typename T>
static class EnumParser
{
	map <string, T> enumMap;
public:
	EnumParser() {};

	T ParseSomeEnum(const string &value)
	{
		map <string, T>::const_iterator iValue = enumMap.find(value);
		if (iValue == enumMap.end())
			throw runtime_error("");
		return iValue->second;
	}
};

EnumParser<IngredientType>::EnumParser()
{
	enumMap["baksteen"] = baksteen;
	enumMap["bloem"] = bloem;
	enumMap["bot"] = bot;
	enumMap["brood"] = brood;
	enumMap["auto"] = car;
	enumMap["kaas"] = cheese;
	enumMap["diamand"] = diamont;
	enumMap["ei"] = egg;
	enumMap["oog"] = eye;
	enumMap["bloempot"] = bloempot;
	enumMap["tand"] = tand;
	enumMap["parel"] = parel;
	enumMap["paddestoel"] = paddestoel;
	enumMap["slijmbal"] = slimeball;
}


#endif