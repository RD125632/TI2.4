#include "StoryScreen.h"
#include "GlobalCollector.h"
#include "Ingredient.h"
#include <iostream>
GLfloat UpwardsScrollVelocity = -10.0;
float view = 20.0;

string quote[6];
int numberOfQuotes = 0, i;
StoryScreen::StoryScreen() : Screen()
{
	
	screenToDraw = &StoryScreen::drawIntroScreen;
	
}
void StoryScreen::drawIntroScreen()
{
	//glPushMatrix();
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//glOrtho(0, 4000, -50, 2000, 5, -5);
	//glMatrixMode(GL_MODELVIEW);
	//glEnable(GL_COLOR_MATERIAL);
	//glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	//string speedtext = "test test test test test test test";
	//glLoadIdentity();
	//glTranslatef(0, 140, 0);
	//for (int i = 0; i < speedtext.length(); i++)
	//{
	//	glutStrokeCharacter(GLUT_STROKE_ROMAN, speedtext[i]);
	//}
	 glMatrixMode(GL_PROJECTION);
	 glPushMatrix();
	 glLoadIdentity();
	 glEnable(GL_COLOR_MATERIAL);
	 glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	 glOrtho(-2000, 2000, -2000, 2000, 5, -5);
	 glMatrixMode(GL_MODELVIEW);
	int l, lenghOfQuote, i;
	for (l = 0;l<numberOfQuotes;l++)
	{
		lenghOfQuote = quote[l].length();
		//glPushMatrix();
		//glTranslated(10, 100, 10);
		glTranslatef(-(lenghOfQuote * 37), -(l * 200), 0.0);
		//glTranslatef(0, 1800, 0);
		for (i = 0; i < lenghOfQuote; i++)
		{
			glColor3f((UpwardsScrollVelocity / 10) + 300 + (l * 10), (UpwardsScrollVelocity / 10) + 300 + (l * 10), 0.0);
			glutStrokeCharacter(GLUT_STROKE_ROMAN, quote[l][i]);
		}
		glPopMatrix();
	}
	/*string scoretext = "Score: " + std::to_string(score);
	for (int i = 0; i < scoretext.length(); i++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, scoretext[i]);
	}*/
	


	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
void StoryScreen::drawGameScreen()
{
	//Models
	glPolygonMode(GL_FRONT_AND_BACK, mode);
	glPushMatrix();
	GlobalCollector::Instance()->room->draw();

	if (!isUpsideDown)
	{
		glScalef(-1, 1, 1);
	}
	else
	{
		glScalef(-1, -1, 1);
	}

	GlobalCollector::Instance()->plank.draw();
	//glTranslated(-25, 25, 45);
	for (Ingredient ing : GlobalCollector::Instance()->ingredients)
	{
		ing.draw();
		//glTranslated(5, 0, 0);
	}
	GlobalCollector::Instance()->wizard.draw();


	glPopMatrix();
	glFlush();
	glutSwapBuffers();

	
}
int StoryScreen::Display()
{
	(this->*screenToDraw)();
	return 0;
}

int StoryScreen::Setup(int windowWidth, int windowHeight)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.00392156862f, 0.00784313725f, 0.01176470588f, 1.0f);

	glViewport(0, 0, windowWidth, windowHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(90, (float)windowWidth / windowHeight, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	gluLookAt(GlobalCollector::Instance()->camera.currentlocation[0], GlobalCollector::Instance()->camera.currentlocation[1], GlobalCollector::Instance()->camera.currentlocation[2],
		0, 20, 20,
		0, 1, 0);
	std::cout << GlobalCollector::Instance()->camera.currentlocation[0] << GlobalCollector::Instance()->camera.currentlocation[1] << GlobalCollector::Instance()->camera.currentlocation[2] << endl;
	quote[0] = "Luke, I am your father!.";
	quote[1]=	"Obi-Wan has taught you well. ";
	quote[2]= "The force is strong with this one. ";
	quote[3]= "Alert all commands. Calculate every possible destination along their last known trajectory. ";
	quote[4]= "The force is with you, young Skywalker, but you are not a Jedi yet.";
	numberOfQuotes = 5;
	return 1;
}
