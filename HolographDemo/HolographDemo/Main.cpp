/*-------------------------------------------------------------------------*/
/*				INCLUDES						                           */
/*-------------------------------------------------------------------------*/

#include "GL/freeglut.h"
#include "ObjModel.h"
#include "Statemanager.h"
#include <vector>
#include "LeapHandler.h"
#include <iostream>
#include "Sound.h"

/*-------------------------------------------------------------------------*/
/*				Local Variable                                             */
/*-------------------------------------------------------------------------*/

	bool activeWindow = true;

	GLint hologramWindow, storyWindow;
	GLint windowWidth, windowHeight;
	float zoom = 1;
	
	Statemanager* statemanager = NULL;
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
		statemanager->HologramScreens.at(statemanager->HologramState).rotateY += 0.5;
		glutPostRedisplay();
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
		// Set Window
		statemanager->HologramScreens.at(statemanager->HologramState).Setup(windowWidth, windowHeight);

		//Models
		statemanager->HologramScreens.at(statemanager->HologramState).Display();
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
		statemanager->StoryScreens.at(statemanager->StoryState).Setup(windowWidth, windowHeight);
		//Models
		statemanager->StoryScreens.at(statemanager->StoryState).Display();
	}

	void HologramReshape(int width, int height)
	{
		windowWidth = width;
		windowHeight = height;
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
			statemanager->HologramScreens.at(statemanager->HologramState).zoom = statemanager->HologramScreens.at(statemanager->HologramState).zoom + 1.5f;
			statemanager->StoryScreens.at(statemanager->StoryState).zoom = statemanager->StoryScreens.at(statemanager->StoryState).zoom + 1.5f;
			break;
		case 's':
			statemanager->HologramScreens.at(statemanager->HologramState).zoom = statemanager->HologramScreens.at(statemanager->HologramState).zoom - 1.5f;
			statemanager->StoryScreens.at(statemanager->StoryState).zoom = statemanager->StoryScreens.at(statemanager->StoryState).zoom - 1.5f;
			break;
		case 'q':
			statemanager->HologramScreens.at(statemanager->HologramState).rotateX -= 0.5;
			break;
		case 'a':
			statemanager->HologramScreens.at(statemanager->HologramState).rotateX += 0.5;
			break;
		case 't':
			if (statemanager->HologramScreens.at(statemanager->HologramState).mode == GL_FILL)
			{
				statemanager->HologramScreens.at(statemanager->HologramState).mode = GL_LINE;
				statemanager->StoryScreens.at(statemanager->StoryState).mode = GL_LINE;
			}
			else
			{
				statemanager->HologramScreens.at(statemanager->HologramState).mode = GL_FILL;
				statemanager->StoryScreens.at(statemanager->StoryState).mode = GL_FILL;
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
			statemanager->HologramScreens.at(statemanager->HologramState).PreviousItem();
			statemanager->HologramScreens.at(statemanager->HologramState).debugMode = true;
			break;
		case GLUT_KEY_RIGHT:
			statemanager->HologramScreens.at(statemanager->HologramState).NextItem();
			statemanager->HologramScreens.at(statemanager->HologramState).debugMode = true;
			break; 
		case GLUT_KEY_F11:
			glutFullScreenToggle();
			break;
		case GLUT_KEY_DOWN:
			statemanager->HologramScreens.at(statemanager->HologramState).isUpsideDown = !statemanager->HologramScreens.at(statemanager->HologramState).isUpsideDown;
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
	std::cout << argv[0];

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
	statemanager = new Statemanager(hologramWindow, storyWindow);

	SampleListener listener;
	Controller controller;

	controller.addListener(listener);
	S_Engine = new SoundEngine();
	RegisterAllSounds();

	glutMainLoop();


	return 0;
}