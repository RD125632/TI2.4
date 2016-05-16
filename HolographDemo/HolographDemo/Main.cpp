/*-------------------------------------------------------------------------*/
/*				INCLUDES						                           */
/*-------------------------------------------------------------------------*/

#include "GL/freeglut.h"
#include "Cube.h"
#include "ObjModel.h"

/*-------------------------------------------------------------------------*/
/*				Local Variable                                             */
/*-------------------------------------------------------------------------*/

	float Holographicwidth = 600;
	float Holographicheight = 600;
	float rotateX, rotateY, rotateZ = 0.0f;
	double trX, trY = 0;
	bool perspectiveFlag = true;
	Cube c1;
	ObjModel obj = ObjModel("models/cube/cube-textures.obj");
	GLenum mode = GL_FILL;
	GLint holographic;
	GLint second;

/*-------------------------------------------------------------------------*/
/*				Function Prototyping                                       */
/*-------------------------------------------------------------------------*/

	void Idle(void);
	void HolographicInit(void);
	void HolographicSetupWindow(void);
	void HolographicPaintComponent(void);
	void SecondPaintComponent(void);
	
	void HolographicReshapeWindow(int, int);

	void KeyEvent(unsigned char, int, int);


/*-------------------------------------------------------------------------*/
/*              Start Code												   */
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/*              -- Window Functions										   */
/*-------------------------------------------------------------------------*/

	
	void Idle(void)
	{
		rotateY += 0.05f;
		rotateX += 0.05f;
		glutPostRedisplay();
		if (glutGetWindow() != holographic)
		{
			glutSetWindow(holographic);
		}
		else
		{
			glutSetWindow(second);
		}
	}

	void HolographicInit(void)
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
	}

	void HolographicSetupWindow(void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		glViewport(0, 0, Holographicwidth, Holographicheight);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(90, (Holographicwidth/Holographicwidth), 0.1f, 100);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 0, -4,
			0, 0, 0,
			0, 1, 0);
	}

	void HolographicPaintComponent(void)
	{
		// Reset window
		HolographicSetupWindow();

		glPolygonMode(GL_FRONT_AND_BACK, mode);
		
		// Cube 1
		glPushMatrix();
			glRotatef(rotateY, 0.0, 1.0, 0.0);
			glRotatef(rotateX, 1.0, 0.0, 0.0);
			//c1.draw();
			obj.draw();
		glPopMatrix();

		glFlush();
		glutSwapBuffers();
	}

	void SecondPaintComponent(void)
	{
		// Reset window
		glPolygonMode(GL_FRONT_AND_BACK, mode);

		glFlush();
		glutSwapBuffers();
	}
	
	void HolographicReshapeWindow(int w, int h)
	{
		Holographicwidth = w;
		Holographicheight = h;
	}


/*-------------------------------------------------------------------------*/
/*              -- Event Handlers										   */
/*-------------------------------------------------------------------------*/

	void KeyEvent(unsigned char key, int mouseX, int mouseY)
	{

		if (key == 27)
		{
			exit(0);
		}
		
		glutPostRedisplay();
	}



int main(int argc, char *argv[])
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(int(Holographicwidth), int(Holographicheight));
	glutInit(&argc, argv);
	holographic = glutCreateWindow("Hologram");
	glutDisplayFunc(HolographicPaintComponent);
	glutIdleFunc(Idle);
	glutReshapeFunc(HolographicReshapeWindow);
	glutKeyboardFunc(KeyEvent);
	glutInitWindowSize(1920, 1080);
	HolographicInit();
	second = glutCreateWindow("2D Graphics");
	glutIdleFunc(Idle);
	glutDisplayFunc(SecondPaintComponent);
	//glutReshapeFunc(ReshapeWindow);
	glutKeyboardFunc(KeyEvent);
	glutMainLoop();
	return 0;
}








