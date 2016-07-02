/*-------------------------------------------------------------------------*/
/*				INCLUDES						                           */
/*-------------------------------------------------------------------------*/

#include "GL/freeglut.h"
#include "ObjModel.h"
#include "GlobalCollector.h"
#include <vector>
#include "Sound.h"

/*-------------------------------------------------------------------------*/
/*				Local Variable                                             */
/*-------------------------------------------------------------------------*/

	bool activeWindow = true;

	GLint hologramWindow, storyWindow;
	GLint hWindowWidth, hWindowHeight;
	GLint sWindowWidth, sWindowHeight;
	float zoom = 1;
	


/*-------------------------------------------------------------------------*/
/*				Function Prototyping                                       */
/*-------------------------------------------------------------------------*/

	void Idle(void);

	void HologramInit(void);
	void HologramPaintComponent(void);

	void StoryInit(void);
	void StoryPaintComponent(void);

	void HologramReshape(int width, int heigth);
	void StoryReshape(int width, int heigth);

	void KeyEvent(unsigned char, int, int);
	void SpecialKeyEvent(int, int, int);

/*-------------------------------------------------------------------------*/
/*              Start Code												   */
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/*              -- Window Functions										   */
/*-------------------------------------------------------------------------*/

	void Idle(void)
	{
		if (glutGetWindow() != hologramWindow)
		{
			glutSetWindow(hologramWindow);
		}
		else
		{
			glutSetWindow(storyWindow);
		}
		GlobalCollector::Instance()->holoScreen.rotateY += 0.5;
		GlobalCollector::Instance()->holoScreen.Logic();
		GlobalCollector::Instance()->camera.MoveToTarget();
		glutPostRedisplay();
	}
	//void finalinit()
	void GameInit(void)
	{
		GlobalCollector::Instance()->holoScreen.init();
		int counter = 0;
		for (int i = 0; i < GlobalCollector::Instance()->ingredients.size();i++)
		{
			GlobalCollector::Instance()->ingredients[i].posX = -25.0f + 5 * counter;
			GlobalCollector::Instance()->ingredients[i].posY = 15.0f;
			GlobalCollector::Instance()->ingredients[i].posZ = 45.0f;
			counter++;
		}
		GlobalCollector::Instance()->plank.scale = 10;
		GlobalCollector::Instance()->plank.posZ = 50;
		GlobalCollector::Instance()->plank.posY = 10;
		GlobalCollector::Instance()->plank.rotX = 90;
		GlobalCollector::Instance()->wizard.posX = 25;
		GlobalCollector::Instance()->wizard.posY = -25;
		GlobalCollector::Instance()->wizard.posZ = 45;
		GlobalCollector::Instance()->wizard.rotY = 180;
		GlobalCollector::Instance()->wizard.rotX = 90;
		GlobalCollector::Instance()->wizard.scale = 4;
	}
	void HologramInit(void)
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_TEXTURE_2D);
		GLfloat LightAmbient[] = { 0.2f, 0.2f, 0.2f, 0.1f };
		glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient); 
		GLfloat LightDiffuse[] = { 0.1f, 0.5f, 1.0f, 1.0f };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
		//GLfloat LightPosition[] = { 0, 1, 3, 0 };
		GLfloat LightPosition[] = { 0, 3, 3, 0.1f };
		glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
		
	}

	void HologramPaintComponent(void)
	{
		GlobalCollector::Instance()->holoScreen.Setup(hWindowWidth, hWindowHeight);
		GlobalCollector::Instance()->holoScreen.Display();
	}

	void StoryInit(void)
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT1);
		glEnable(GL_TEXTURE_2D);
		GLfloat LightAmbient[] = { 0.1f, 0.1f, 0.1f, 0.1f };
		glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
		GLfloat LightDiffuse[] = { 0.1f, 0.5f, 1.0f, 1.0f };
		glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
		//GLfloat LightPosition[] = { 0, 1, 3, 0 };
		GLfloat LightPosition[] = { -1, -1, 0, 0 };
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);

	}

	void StoryPaintComponent(void)
	{
		GlobalCollector::Instance()->storyScreen.Setup(sWindowWidth, sWindowHeight);
		GlobalCollector::Instance()->storyScreen.Display();
	}

	void HologramReshape(int width, int heigth)
	{
		hWindowWidth = width;
		hWindowHeight = heigth;
		glutPostRedisplay();
	}

	void StoryReshape(int width, int heigth)
	{
		sWindowWidth = width;
		sWindowHeight = heigth;
		glutPostRedisplay();
	}


/*-------------------------------------------------------------------------*/
/*              -- Event Handlers										   */
/*-------------------------------------------------------------------------*/

	void KeyEvent(unsigned char key, int mouseX, int mouseY)
	{

		switch (key)
		{
		case 27:
			exit(0);
			break;
		case 'w':
			GlobalCollector::Instance()->holoScreen.zoom += 1.5f;
			GlobalCollector::Instance()->storyScreen.zoom += 1.5f;
			break;
		case 's':
			GlobalCollector::Instance()->holoScreen.zoom -= 1.5f;
			GlobalCollector::Instance()->storyScreen.zoom -= 1.5f;
			break;
		case 'q':
			GlobalCollector::Instance()->holoScreen.rotateX += 0.5;
			break;
		case 'a':
			GlobalCollector::Instance()->holoScreen.rotateX -= 0.5;
			GlobalCollector::Instance()->holoScreen.SetCurrentItem(&GlobalCollector::Instance()->book); //debug, verwijder wanneer af
			break;
		case 'd':
			GlobalCollector::Instance()->holoScreen.ShowBook(true);
			break;
		case '9':
			GlobalCollector::Instance()->storyScreen.SwitchScreens(1);
			break;
		case'0':
			GlobalCollector::Instance()->storyScreen.SwitchScreens(2);
			break;
		case'-':
			GlobalCollector::Instance()->storyScreen.PrepareScoreScreen();
			GlobalCollector::Instance()->storyScreen.SwitchScreens(3);
			break;
		case ']':
			GlobalCollector::Instance()->storyScreen.SwitchScreens(4);
			break;
		case 't':
			if (GlobalCollector::Instance()->holoScreen.mode == GL_FILL)
			{
				GlobalCollector::Instance()->holoScreen.mode = GL_LINE;
				GlobalCollector::Instance()->storyScreen.mode = GL_LINE;
			}
			else
			{
				GlobalCollector::Instance()->holoScreen.mode = GL_FILL;
				GlobalCollector::Instance()->storyScreen.mode = GL_FILL;
			}
			break;
		}		
		glutPostRedisplay();
	}

	void SpecialKeyEvent(int key, int mouseX, int mouseY)
	{
		switch(key)
		{
		case GLUT_KEY_LEFT:
			GlobalCollector::Instance()->camera.MoveToLeft();
			break;
		case GLUT_KEY_RIGHT:
			GlobalCollector::Instance()->camera.MoveToRight();
			break; 
		case GLUT_KEY_F11:
			glutFullScreenToggle();
			break;
		case GLUT_KEY_DOWN:
			GlobalCollector::Instance()->holoScreen.isUpsideDown = !GlobalCollector::Instance()->holoScreen.isUpsideDown;
			GLfloat lightposition[] = { 0,0,0,0 };
			glGetLightfv(GL_LIGHT1, GL_POSITION, lightposition);
			lightposition[1] = -lightposition[1];
			glLightfv(GL_LIGHT1, GL_POSITION, lightposition);
			break;
		}
		
	}

	void RegisterAllSounds() {
		/**
		In this function you can register your sounds.
		example: GlobalCollector::Instance()->soundEngine.RegisterSound("Magic", "sounds/magic.wav"); (1st parameter is name, 2nd parameter is path)
		play a sound: GlobalCollector::Instance()->soundEngine.Play_Sound("Magic", true); (1st parameter is name, 2nd parameter is looping)
		stop a sound: GlobalCollector::Instance()->soundEngine.Stop_Sound();
		ONLY PLAYS WAV!
		**/
		GlobalCollector::Instance()->soundEngine.RegisterSound("Magic", "sounds/magic.wav");
		GlobalCollector::Instance()->soundEngine.RegisterSound("Splash", "sounds/splash.wav");
		GlobalCollector::Instance()->soundEngine.RegisterSound("Pickup", "sounds/pickup.wav");
		GlobalCollector::Instance()->soundEngine.RegisterSound("Boil", "sounds/boil.wav");
		GlobalCollector::Instance()->soundEngine.RegisterSound("Book", "sounds/book.wav");
		GlobalCollector::Instance()->soundEngine.RegisterSound("Music", "sounds/music.wav");
	}

int main(int argc, char *argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(1000, 600);
	hologramWindow = glutCreateWindow("Hologram");
	HGLRC hRCA = wglGetCurrentContext();
	glutDisplayFunc(HologramPaintComponent);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyEvent);
	glutSpecialFunc(SpecialKeyEvent);
	glutReshapeFunc(HologramReshape);
	HologramInit();

	glutInitWindowSize(1000, 600);
	storyWindow = glutCreateWindow("Story");
	HGLRC hRCB = wglGetCurrentContext();
	glutDisplayFunc(StoryPaintComponent);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyEvent);
	glutSpecialFunc(SpecialKeyEvent);
	glutReshapeFunc(StoryReshape);
	StoryInit();
	wglShareLists(hRCA, hRCB);
	GameInit();




	RegisterAllSounds();

	glutMainLoop();
	return 0;
}