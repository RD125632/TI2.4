#include "StoryScreen.h"
#include "GlobalCollector.h"
#include "Ingredient.h"
#include <iostream>
#include <vector>
GLfloat UpwardsScrollVelocity = -10.0;
float view = 20.0;
std::vector<string> story;

void init()
{
	std::ifstream input("Text/StoryIntro.txt");


	for (std::string line; getline(input, line); )
	{
		story.push_back(line);
	}



	
}
StoryScreen::StoryScreen() : Screen()
{
	
	screenToDraw = &StoryScreen::drawIntroScreen;
	init();
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
	 GLdouble *matrix = new GLdouble[16];
	 glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	 glLoadIdentity();
	 glOrtho(0, 800, 0, 600, -5, 5);
	 glMatrixMode(GL_MODELVIEW);
	 glLoadIdentity();
	 glPushMatrix();

	 glLoadIdentity();
	 glDisable(GL_TEXTURE_2D);
	 glDisable(GL_LIGHTING);
	 glEnable(GL_COLOR);
	 glColor3f(1.0f, 1.0f, 1.0f);
	 for (int i = 0; i < story.size() ; i++)
	 {
		 glRasterPos2i(10, 580-(i*12));
		 for (int k = 0; k < story[i].length();k++)
		 {
			 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, story[i][k]);
		 }
	 }
	 glPopMatrix();
	 glDisable(GL_COLOR);
	 glEnable(GL_TEXTURE_2D);
	 glEnable(GL_LIGHTING);
	 glMatrixMode(GL_PROJECTION);
	 glLoadMatrixd(matrix);
	 glMatrixMode(GL_MODELVIEW);
	 glColor3f(1.0f, 1.0f, 1.0f);


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
	return 1;
}
