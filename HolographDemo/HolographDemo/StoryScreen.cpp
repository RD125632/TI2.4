#include "StoryScreen.h"
#include "GlobalCollector.h"
#include "Ingredient.h"
#include <iostream>
#include <vector>
#include "Texture.h"
GLfloat UpwardsScrollVelocity = -10.0;
float view = 20.0;
std::vector<string> story;
std::vector<string> book;
std::vector<string> ending;
Texture * background;
void init()
{
	std::ifstream input1("Text/StoryIntro.txt");
	
	//std::ifstream input3("Text/StoryEnding.txt");

	for (std::string line; getline(input1, line); )
	{
		story.push_back(line);
	}
	/*std::ifstream input2("Text/ingredienteBoek.txt");
	for (std::string line1; getline(input2, line1); )
	{
		book.push_back(line1);
	}*/
	/*for (std::string line; getline(input3, line); )
	{
		ending.push_back(line);
	}*/
	for (int y : GlobalCollector::Instance()->wizard.symptoms)
	{
		for (Symptom s : GlobalCollector::Instance()->symptoms)
		{
			if (s.ID == y)
			{
				story.push_back(s.description);
			}
		}
		
	}
	background = new Texture("resources/parchment.png");

	
}
StoryScreen::StoryScreen() : Screen()
{
	
	screenToDraw = &StoryScreen::drawIntroScreen;
	init();
}
void drawBackground()
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
		toDraw = story;
		break;
	case 1:
		toDraw = book;
		break;
	case 2:
		toDraw = ending;
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
	 for (int i = 0; i < toDraw.size() ; i++)
	 {
		 glRasterPos2i(10, 580-(i*12));
		 for (int k = 0; k < toDraw[i].length();k++)
		 {
			 glColor3f(0.0f, 0.0f, 0.0f);
			 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, toDraw[i][k]);
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
		GlobalCollector::Instance()->camera.currentlocation[3], GlobalCollector::Instance()->camera.currentlocation[4], 20,
		0, 1, 0);
	std::cout << GlobalCollector::Instance()->camera.currentlocation[0] << GlobalCollector::Instance()->camera.currentlocation[1] << GlobalCollector::Instance()->camera.currentlocation[2] << endl;
	return 1;
}

void StoryScreen::SwitchScreens(int screen)
{
	switch (screen)
	{
		case 1:
			screenToDraw = &StoryScreen::drawIntroScreen;
		break;
		case 2:
			screenToDraw = &StoryScreen::drawGameScreen;
		break;
		case 3:
		break;

	}
	
}
