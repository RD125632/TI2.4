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
	GLint windowWidth, windowHeight;
	float zoom = 1;
	
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
		GlobalCollector::Instance()->holoScreen.rotateY += 0.5;
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
		GlobalCollector::Instance()->holoScreen.Setup(windowWidth, windowHeight);
		GlobalCollector::Instance()->holoScreen.Display();
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
		GlobalCollector::Instance()->storyScreen.Setup(windowWidth, windowHeight);
		GlobalCollector::Instance()->storyScreen.Display();
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

			break;
		case GLUT_KEY_RIGHT:

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

	S_Engine = new SoundEngine();
	RegisterAllSounds();

	glutMainLoop();
	return 0;
}