/*-------------------------------------------------------------------------*/
/*				INCLUDES						                           */
/*-------------------------------------------------------------------------*/

#include "GL/freeglut.h"
#include "Cube.h"

/*-------------------------------------------------------------------------*/
/*				Local Variable                                             */
/*-------------------------------------------------------------------------*/

	float width = 800;
	float height = 600;
	float rotateX, rotateY, rotateZ = 0.0f;
	double trX, trY = 0;
	bool perspectiveFlag = true;
	Cube c1, c2, c3, c4;
	GLenum mode = GL_LINE;

/*-------------------------------------------------------------------------*/
/*				Function Prototyping                                       */
/*-------------------------------------------------------------------------*/

	void Idle(void);
	void SetupWindow(void);
	void PaintComponent(void);
	
	void ReshapeWindow(int, int);

	void KeyEvent(unsigned char, int, int);


/*-------------------------------------------------------------------------*/
/*              Start Code												   */
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/*              -- Window Functions										   */
/*-------------------------------------------------------------------------*/

	
	void Idle(void)
	{
		rotateY += 0.01f;
		rotateX += 0.01f;
		glutPostRedisplay();
	}

	void SetupWindow(void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		glViewport(0, 0, width, height);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(90, (width/height), 0.1f, 100);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 0, -4,
			0, 0, 0,
			0, 1, 0);
	}

	void PaintComponent(void)
	{
		// Reset window
		SetupWindow();

		glPolygonMode(GL_FRONT_AND_BACK, mode);
		
		// Cube 1
		glPushMatrix();
			glTranslated(0, 2, 0);
			glRotatef(rotateY, 0.0, 1.0, 0.0);
			glRotatef(rotateX, 1.0, 0.0, 0.0);
			c1.draw();
		glPopMatrix();


		// Cube 2
		glPushMatrix();
			glTranslated(2, 0, 0);
			glRotatef(rotateY, 0.0, 1.0, 0.0);
			glRotatef(rotateX, 1.0, 0.0, 0.0);
			c2.draw();
		glPopMatrix();

		// Cube 3
		glPushMatrix();
			glTranslated(0, -2, 0);
			glRotatef(rotateY, 0.0, 1.0, 0.0);
			glRotatef(rotateX, 1.0, 0.0, 0.0);
			c3.draw();
		glPopMatrix();

		// Cube 4
		glPushMatrix();
			glTranslated(-2, 0, 0);
			glRotatef(rotateY, 0.0, 1.0, 0.0);
			glRotatef(rotateX, 1.0, 0.0, 0.0);
			c4.draw();
		glPopMatrix();

		glFlush();
		glutSwapBuffers();
	}
	
	void ReshapeWindow(int w, int h)
	{
		width = w;
		height = h;
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
	glutInitWindowSize(int(width), int(height));
	glutInit(&argc, argv);
	glutCreateWindow("3D Objects");
		
	glEnable(GL_DEPTH_TEST);

	glutIdleFunc(Idle);
	glutDisplayFunc(PaintComponent);
	glutReshapeFunc(ReshapeWindow);

	glutKeyboardFunc(KeyEvent);
	glutMainLoop();
	return 0;
}








