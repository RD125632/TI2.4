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
HDC hDC = NULL;

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
	background = new Texture("resources/book.png");
}

void StoryScreen::drawBackground()
{
	int height = 500;
	int width = 550;
	glEnable(GL_TEXTURE_2D);
	background->bind();
	glTranslatef(125, 50, 0);
	glBegin(GL_QUADS);    
	glNormal3f(0.0, 0.0, -1.0);		
	glTexCoord2f(1, 1);				glVertex3f(width, height ,-1);
	glTexCoord2f(1, 0);				glVertex3f(width, 0, -1);
	glTexCoord2f(0, 0);				glVertex3f(0, 0, -1);			
	glTexCoord2f(0, 1);				glVertex3f(0, height, -1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
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

void StoryScreen::drawBookScreens()
{
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

	std::vector<string> bookPageLeft;
	std::vector<string> bookPageRight;
	int z = 0;

	switch (storyStatus)
	{
	case 0:
		bookPageLeft = GlobalCollector::Instance()->storyBegin;
		break;
	case 1:

		for (std::string s : GlobalCollector::Instance()->storyBook)
		{
			if (std::string::npos != s.find(":"))
			{
				z++;
			}

			if (z < 8)
			{
				bookPageLeft.push_back(s);
			}
			else
			{
				bookPageRight.push_back(s);
			}		
		}
		
		break;
	case 2:
			bookPageLeft = GlobalCollector::Instance()->storyEnd;
			
			completeList.clear();
			usedList.clear();
			completeList.push_back("Goede Ingredienten:");
			usedList.push_back("Foute Ingredienten:");

			for (int z : GlobalCollector::Instance()->wizard.symptoms)
			{
				for (string s : GlobalCollector::Instance()->ketel.GetIngredients())
				{
					Ingredient curIng;
					for (Ingredient ing : GlobalCollector::Instance()->ingredients)
					{
						if (ing.name == s)
						{
							curIng = ing;
							break;
						}
					}

					if (curIng.cures == z)
					{
						completeList.push_back(curIng.name);
					}
					else
					{
						usedList.push_back(curIng.name);
					}
				}
			}
			completeList.push_back("");
			usedList.push_back("");

			for (string s : completeList)
			{
				bookPageRight.push_back(s);
			}

			for (string s : usedList)
			{
				bookPageRight.push_back(s);
			}


		break;
	default:
		break;
	}

	for (unsigned int i = 0; i < bookPageLeft.size(); i++)
	{
		glRasterPos2i(40, 425 - (i * 18)); 
		
		for (unsigned int k = 0; k < bookPageLeft[i].length();k++)
		{
			glColor3f(0.0f, 0.0f, 0.0f);
			if (std::string::npos != bookPageLeft[i].find(":"))
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, bookPageLeft[i][k]);
			}
			else if (std::string::npos != bookPageLeft[i].find("~"))
			{
				if (k > 0)
				{
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, bookPageLeft[i][k]);
				}
			}
			else
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, bookPageLeft[i][k]);
			}
		}
	}

	for (unsigned int i = 0; i < bookPageRight.size(); i++)
	{
		glRasterPos2i(300, 425 - (i * 18));
		for (unsigned int k = 0; k < bookPageRight[i].length();k++)
		{
			glColor3f(0.0f, 0.0f, 0.0f);
			if (std::string::npos != bookPageRight[i].find(":"))
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, bookPageRight[i][k]);
			}
			else
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, bookPageRight[i][k]);
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
			storyStatus = 2;
			screenToDraw = &StoryScreen::drawBookScreens;
			
		break;
		case 2:
			screenToDraw = &StoryScreen::drawGameScreen;
		break;
		case 3:
			
			storyStatus = 1;
			screenToDraw = &StoryScreen::drawBookScreens;
		break;
			screenToDraw = &StoryScreen::drawBookScreens;
		break;
		case 5:
			storyStatus = 2;
			screenToDraw = &StoryScreen::drawBookScreens;
		break;

	}
	
}

void StoryScreen::Logic()
{
	GlobalCollector::Instance()->storyBookObject.heightmodifier += 0.2f;
	GlobalCollector::Instance()->storyBookObject.posY = 1;
	GlobalCollector::Instance()->storyBookObject.posY += float(cos(GlobalCollector::Instance()->storyBookObject.heightmodifier * 0.05));
}

int StoryScreen::getScreen() const
{
	return screen;
}
