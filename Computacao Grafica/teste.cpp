#include<windows.h>
#include <GL/glut.h>

float c = 0;
float h = 0;

void corpo() {
  glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
  glVertex3f(3.0 + h, 1.0 + c, 0.0);
  glVertex3f(5.0 + h, 1.0 + c, 0.0);
  glVertex3f(5.0 + h, 6.0 + c, 0.0);
  glVertex3f(3.0 + h, 6.0 + c, 0.0);
	glEnd();
}

void bico() {
  glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(3.0 + h, 6.0 + c, 0.0);
	glVertex3f(4.0 + h, 8.0 + c, 0.0);
	glVertex3f(5.0 + h, 6.0 + c, 0.0);
	glEnd();
}

void asaEsquerda() {
  glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(1.5 + h, 1.0 + c, 0.0);
	glVertex3f(3.0 + h, 1.0 + c, 0.0);
	glVertex3f(3.0 + h, 3.0 + c, 0.0);
	glEnd();
}

void asaDireita() {
  glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(5.0 + h, 1.0 + c, 0.0);
	glVertex3f(6.5 + h, 1.0 + c, 0.0);
	glVertex3f(5.0 + h, 3.0 + c, 0.0);
	glEnd();
}

void fogo() {
	glBegin(GL_TRIANGLES);
	glVertex3f(3.0 + h, 1.0 + c, 0.0);
	glVertex3f(5.0 + h, 1.0 + c, 0.0);
	glEnd();
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	//glScalef(1.0f,1.0f,0.1f);
	glTranslatef(4.0,4.5,0.0);
	glRotatef(45,0.0f,0.0f,1.0f);
	glTranslatef(-4.0,-4.5,0.0);
	corpo();
	bico();
	asaEsquerda();
	asaDireita();

	glFlush();
}

void Init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20.0, 20.0, -20.0, 20.0, -1.0, 1.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyInput(unsigned char key, int x, int y) {
	switch (key) {
    case 27:
		exit(0);
		break;
	case 'w':
		c += 0.5;
		break;
	case 's':
		c -= 0.5;
		break;
	case 'd':
		h += 0.5;
		break;
	case 'a':
		h -= 0.5;
		break;
    default:
		break;
	}

	drawScene();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	
	glutCreateWindow("foguete.cpp");
	
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	Init();

	glutMainLoop();
}