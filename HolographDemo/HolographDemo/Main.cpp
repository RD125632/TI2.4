/*-------------------------------------------------------------------------*/
/*				INCLUDES						                           */
/*-------------------------------------------------------------------------*/

#include "GL/freeglut.h"
#include "ObjModel.h"
#include "Statemanager.h"
#include <vector>
#include "Sound.h"
#include "StoryScreen.h"
#include "HologramScreen.h"
#include "ObjectManager.h"

/*-------------------------------------------------------------------------*/
/*				Local Variable                                             */
/*-------------------------------------------------------------------------*/

	bool activeWindow = true;

	GLint hologramWindow, storyWindow;
	GLint windowWidth, windowHeight;
	float zoom = 1;
	static ObjectManager *objectManager;
	static StoryScreen storyScreen;
	static HologramScreen hologramScreen;
	//Statemanager* statemanager = NULL;
	SoundEngine* S_Engine = NULL;


/*-------------------------------------------------------------------------*/
/*				Function Prototyping                                       */
/*-------------------------------------------------------------------------*/

	void Idle(void);

	void HologramInit(void);
	void HologramPaintComponent(void);

	void StoryInit(void);
	void StoryPaintComponent(void);

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
		hologramScreen.rotateY += 0.5;
		glutPostRedisplay();
	}

	void ObjectInit(void)
	{
		objectManager = new ObjectManager();

		hologramScreen.objects.push_back(objectManager->ketel); //moet verbeterd worden

	}

	void HologramInit(void)
	{
		windowHeight = 1080;
		windowWidth = 1920;
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

	void HologramPaintComponent(void)
	{
		hologramScreen.Setup(windowWidth, windowHeight);
		hologramScreen.Display();
	}

	void StoryInit(void)
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_TEXTURE_2D);
		GLfloat LightAmbient[] = { 0.1f, 0.1f, 0.1f, 0.1f };
		glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
		GLfloat LightDiffuse[] = { 0.1f, 0.5f, 1.0f, 1.0f };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
		GLfloat LightPosition[] = { -1, -1, 0, 0 };
		glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	}

	void StoryPaintComponent(void)
	{
		storyScreen.Setup(windowWidth,windowHeight);
		storyScreen.Display();
	}

	void HologramReshape(int width, int heigth)
	{
		windowWidth = width;
		windowHeight = heigth;
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
			hologramScreen.zoom += 1.5;
			storyScreen.zoom += 1.5;
			break;
		case 's':
			hologramScreen.zoom -= 1.5;
			storyScreen.zoom -= 1.5;
			break;
		case 'q':
			hologramScreen.rotateX -= 0.5f;
			break;
		case 'a':
			hologramScreen.rotateX += 0.5f;
			break;
		case 't':
			if (hologramScreen.mode == GL_FILL)
			{
				hologramScreen.mode = GL_LINE;
				storyScreen.mode = GL_LINE;
			}
			else
			{
				hologramScreen.mode = GL_FILL;
				storyScreen.mode = GL_FILL;
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
			/*statemanager->HologramScreens.at(statemanager->HologramState).PreviousItem();
			statemanager->HologramScreens.at(statemanager->HologramState).debugMode = true;*/
			break;
		case GLUT_KEY_RIGHT:
			/*statemanager->HologramScreens.at(statemanager->HologramState).NextItem();
			statemanager->HologramScreens.at(statemanager->HologramState).debugMode = true;*/
			break; 
		case GLUT_KEY_F11:
			glutFullScreenToggle();
			break;
		case GLUT_KEY_DOWN:
			hologramScreen.isUpsideDown = !hologramScreen.isUpsideDown;
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
		example: S_Engine->RegisterSound("Magic", "sounds/magic.wav"); (1st parameter is name, 2nd parameter is path)
		play a sound: S_Engine->Play_Sound("Magic", true); (1st parameter is name, 2nd parameter is looping)
		stop a sound: S_Engine->Stop_Sound();
		ONLY PLAYS WAV!
		**/
		S_Engine->RegisterSound("Magic", "sounds/magic.wav");
		S_Engine->RegisterSound("Splash", "sounds/splash.wav");
		S_Engine->RegisterSound("Pickup", "sounds/pickup.wav");
		S_Engine->RegisterSound("Boil", "sounds/boil.wav");
		S_Engine->RegisterSound("Book", "sounds/book.wav");
		S_Engine->RegisterSound("Music", "sounds/music.wav");
	}

int main(int argc, char *argv[])
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	glutInitWindowSize(1920, 1080);
	hologramWindow = glutCreateWindow("Hologram");
	glutDisplayFunc(HologramPaintComponent);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyEvent);
	glutSpecialFunc(SpecialKeyEvent);
	glutReshapeFunc(HologramReshape);
	HologramInit();

	glutInitWindowSize(1920, 1080);
	storyWindow = glutCreateWindow("Story");
	glutDisplayFunc(StoryPaintComponent);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyEvent);
	glutSpecialFunc(SpecialKeyEvent);
	StoryInit();
	ObjectInit();
	S_Engine = new SoundEngine();
	RegisterAllSounds();

	glutMainLoop();
	return 0;
}