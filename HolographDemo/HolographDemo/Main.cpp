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

	float rotateX, rotateY, rotateZ = 0.0f;
	float zoom = 1;
	bool activeWindow = true;

	std::vector<ObjModel*> objmodels;
	std::vector<GLint> windows;

	GLint hologramWindow, storyWindow;
	GLenum mode = GL_FILL;
	


/*-------------------------------------------------------------------------*/
/*				Function Prototyping                                       */
/*-------------------------------------------------------------------------*/

	void Idle(void);
	void Init(void);
	void SetupWindow(void);
	void PaintComponent(void);

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
		windows.push_back(storyWindow);
		windows.push_back(hologramWindow);

		HologramInit();
	}

	void Idle(void)
	{
		activeWindow = !activeWindow;
		glutSetWindow(windows[activeWindow]);
		glutPostRedisplay();
	}

	void HologramInit(void)
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glEnable(GL_TEXTURE_2D);
		GLfloat LightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
		glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
		GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
		GLfloat LightPosition[] = { 0, -1, 0, 0 };
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
		objmodels.push_back(new ObjModel("models/ketel/ketel.obj"));
	}

	void HologramSetup(void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		glViewport(0, 0, 1080, 1080);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(90, 1, 0.1f, 100);

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

		glutSwapBuffers();
	}

	void StoryInit(void)
	{

	}

	void StorySetup(void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		glViewport(0, 0, 1080, 1080);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(90, 1, 0.1f, 100);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 0, -4,
			0, 0, 0,
			0, 1, 0);
	}

	void StoryPaintComponent(void)
	{

		glutSwapBuffers();
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
			zoom = zoom*2;
			break;
		case 's':
			zoom = zoom/2;
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
	glutInitWindowSize(1920, 1080);
	HologramInit();

	glutInitWindowSize(1920, 1080);
	storyWindow = glutCreateWindow("Story");
	glutDisplayFunc(StoryPaintComponent);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyEvent);
	glutSpecialFunc(SpecialKeyEvent);
	glutInitWindowSize(1920, 1080);
	StoryInit();

	glutMainLoop();
	return 0;
}