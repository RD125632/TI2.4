#include "StoryScreen.h"
#include "GlobalCollector.h"
#include "Ingredient.h"
#include <iostream>
#include <vector>
#include "Texture.h"

GLfloat UpwardsScrollVelocity = -10.0;
float view = 20.0;
std::vector<string> story;
vector<string> completeList;
vector<string> usedList;
Texture * background;

void StoryScreen::init()
{
	std::ifstream input("Text/StoryIntro.txt");

	for (std::string line; getline(input, line); )
	{
		story.push_back(line);
	}
}

StoryScreen::StoryScreen() : Screen()
{
	
	SwitchScreens(1);
	background = new Texture("resources/parchment.png");
}

void StoryScreen::drawBackground()
{
	int size = 800;
	glEnable(GL_TEXTURE_2D);
	background->bind();
	glBegin(GL_QUADS);      //and draw a face
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(1, 0);
	glVertex3f(800, 600, -1);
	glTexCoord2f(0, 0);
	glVertex3f(0, 600, -1);
	glTexCoord2f(0, 1);
	glVertex3f(0, 0, -1);
	glTexCoord2f(1, 1);
	glVertex3f(800, 0, -1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void StoryScreen::drawIntroScreen()
{	
	
	std::vector<string> toDraw;

	toDraw.clear();
	switch (storyStatus)
	{
	case 0:
		toDraw = GlobalCollector::Instance()->storyBegin;
		break;
	case 1:
		toDraw = GlobalCollector::Instance()->storyBook;
		break;
	case 2:
		toDraw = GlobalCollector::Instance()->storyEnd;
		break;
	default:
		break;
	}

	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
	 drawBackground();
	 glColor3f(0.0f, 0.0f, 0.0f);

	 for (unsigned int i = 0; i < toDraw.size() ; i++)
	 {
		 glRasterPos2i(10, 580-(i*12));
		 for (unsigned int k = 0; k < toDraw[i].length();k++)
		 {
			 glColor3f(0.0f, 0.0f, 0.0f);
			 if (std::string::npos != toDraw[i].find(":"))
			 {
				 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, toDraw[i][k]);
			 }
			 else
			 {
				 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, toDraw[i][k]);
			 }
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
	glScalef(1, 1, 1);
	GlobalCollector::Instance()->room->draw();
	glScalef(1.0, 1.0, 1.25);
	GlobalCollector::Instance()->plank.draw();
	//glTranslated(-25, 25, 45);
	for (Ingredient ing : GlobalCollector::Instance()->ingredients)
	{
		ing.draw();
		//glTranslated(5, 0, 0);
	}
	glDisable(GL_BLEND);
	GlobalCollector::Instance()->storyBookObject.draw();
	glEnable(GL_BLEND);
	GlobalCollector::Instance()->wizard.draw();

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glOrtho(-3000, 3000, 0, 5000, -1, 1);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GlobalCollector::Instance()->leaphandler.DrawCube();
	/*glDisable(GL_LINE);
	glDisable(GL_FRONT_AND_BACK);*/
	glPopMatrix();
	glFlush();
	glutSwapBuffers();

	
}

void StoryScreen::drawScoreScreen()
{
	//glPushMatrix();
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
	drawBackground();
	glColor3f(0.0f, 0.0f, 0.0f);
	for (unsigned int i = 0; i < completeList.size(); i++)
	{
		glRasterPos2i(50, 580 - (i * 12));
		for (unsigned int k = 0; k < completeList[i].length(); k++)
		{
			glColor3f(0.0f, 0.0f, 0.0f);
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, completeList[i][k]);
		}
	}
	for (unsigned int i = 0; i < usedList.size(); i++)
	{
		glRasterPos2i(400, 580 - (i * 12));
		for (unsigned int k = 0; k < usedList[i].length(); k++)
		{
			glColor3f(0.0f, 0.0f, 0.0f);
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, usedList[i][k]);
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

	gluLookAt(GlobalCollector::Instance()->camera.currentlocation[0] + GlobalCollector::Instance()->leaphandler.getX() , GlobalCollector::Instance()->camera.currentlocation[1] - GlobalCollector::Instance()->leaphandler.getY(), GlobalCollector::Instance()->camera.currentlocation[2],
		GlobalCollector::Instance()->camera.currentlocation[3], GlobalCollector::Instance()->camera.currentlocation[4], GlobalCollector::Instance()->camera.currentlocation[5],
		0, 1, 0);

	return 1;
}

void StoryScreen::SwitchScreens(int screen)
{
	this->screen = screen;
	switch (screen)
	{
		case 1:
			storyStatus = 0;
			screenToDraw = &StoryScreen::drawIntroScreen;
			
		break;
		case 2:
			screenToDraw = &StoryScreen::drawGameScreen;
		break;
		case 3:
			
			storyStatus = 1;
			screenToDraw = &StoryScreen::drawIntroScreen;
		break;
		case 4:
			PrepareScoreScreen();
			screenToDraw = &StoryScreen::drawScoreScreen;
		break;
		case 5:
			storyStatus = 2;
			screenToDraw = &StoryScreen::drawIntroScreen;
		break;

	}
	
}

void StoryScreen::PrepareScoreScreen()
{
	completeList.clear();
	usedList.clear();
	completeList.push_back("Goede Ingredienten:");
	usedList.push_back("Jouw Ingredienten:");
	for (string s: GlobalCollector::Instance()->ketel.GetIngredients())
	{
		completeList.push_back(s);
		usedList.push_back(s);
	}
}

void StoryScreen::Logic()
{
	GlobalCollector::Instance()->storyBookObject.heightmodifier += 0.2f;
	GlobalCollector::Instance()->storyBookObject.posY = 1;
	GlobalCollector::Instance()->storyBookObject.posY += float(cos(GlobalCollector::Instance()->storyBookObject.heightmodifier * 0.05));
}
