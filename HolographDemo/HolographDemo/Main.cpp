/*-------------------------------------------------------------------------*/
/*				INCLUDES						                           */
/*-------------------------------------------------------------------------*/

#include "GL/freeglut.h"
#include "ObjModel.h"
#include "Statemanager.h"
#include <vector>

/*-------------------------------------------------------------------------*/
/*				Local Variable                                             */
/*-------------------------------------------------------------------------*/

	bool activeWindow = true;

	GLint hologramWindow, storyWindow;
	GLint windowWidth, windowHeight;
	GLenum mode = GL_LINE;
	
	Statemanager statemanager = Statemanager();


/*-------------------------------------------------------------------------*/
/*				Function Prototyping                                       */
/*-------------------------------------------------------------------------*/

	void Init(void);
	void Idle(void);

	void HologramInit(void);
	void HologramSetup(void);
	void HologramPaintComponent(void);

	void StoryInit(void);
	void StorySetup(void);
	void StoryPaintComponent(void);

	void KeyEvent(unsigned char, int, int);
	void SpecialKeyEvent(int, int, int);

/*-------------------------------------------------------------------------*/
/*              Start Code												   */
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/*              -- Window Functions										   */
/*-------------------------------------------------------------------------*/

	void Init(void)
	{
		HologramInit();	
	}

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
		statemanager.HologramScreens.at(statemanager.HologramState).rotateX += 0.5;
		glutPostRedisplay();
	}

	void HologramInit(void)
	{
		windowHeight = 1080;
		windowWidth = 1920;
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glEnable(GL_TEXTURE_2D);
		GLfloat LightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
		glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient); 
		GLfloat LightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
		glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
		GLfloat LightPosition[] = { 0, -1, 0, 0 };
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	}

	void HologramSetup(void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		glViewport((windowWidth-windowHeight)/2, 0, windowHeight, windowHeight);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(90, windowHeight/windowHeight, 0.1f, 100);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 0, -4,
			0, 0, 0,
			0, 1, 0);
	}

	void HologramPaintComponent(void)
	{
		// Set Window
		HologramSetup();

		//Models
		statemanager.HologramScreens.at(statemanager.HologramState).Display();
	}

	void StoryInit(void)
	{

	}

	void StorySetup(void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		glViewport(0, 0, 1920, 1080);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(90, 1920/1080, 0.1f, 100);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 1, -4,
			0, 0, 0,
			0, 1, 0);
	}

	void StoryPaintComponent(void)
	{
		//Models
		statemanager.StoryScreens.at(statemanager.StoryState).Display();
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

		switch(key)
		{
		case 27:
			exit(0);
			break;
		case 'w':
			statemanager.HologramScreens.at(statemanager.HologramState).zoom = statemanager.HologramScreens.at(statemanager.HologramState).zoom*2;
			break;
		case 's':
			statemanager.HologramScreens.at(statemanager.HologramState).zoom = statemanager.HologramScreens.at(statemanager.HologramState).zoom/2;
			break;
		case 'a':
			statemanager.HologramScreens.at(statemanager.HologramState).rotateY -= 0.5;
			break;
		case 'd':
			statemanager.HologramScreens.at(statemanager.HologramState).rotateY += 0.5;
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
		}
		
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

	glutMainLoop();
	return 0;
}