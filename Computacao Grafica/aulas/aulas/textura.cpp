#include <GL/glut.h>
#include <iostream>
#include "texturas/stb_image.h"



GLfloat marrom[4] = { 101.0 / 255,67.0 / 244,33.0 / 255,1 };
GLfloat green[4] = { 0.047, 0.569, 0.027,1 };
GLfloat cinza[4] = { 0.2, 0.2, 0.2, 0.7 };
GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat direction[] = { 0.0, 10.0, 0.0, 1.0 };

void pemesa()
{
	glScalef(0.1, 2, 0.5);
	glutSolidCube(1);
}
void cadeira()
{
	glPushMatrix();
	glTranslatef(-1, -1.4, -0.6);
	pemesa();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1, -1.4, -0.6);
	pemesa();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1, -1.4, 0.9);
	pemesa();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1, -1.4, 0.9);
	pemesa();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -0.4, 0.1);
	glScalef(2, 0.1, 2);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 1, -0.9);
	glScalef(2, 3, 0.1);
	glutSolidCube(1);
	glPopMatrix();
}
void prato() {
	glPushMatrix();
	glTranslatef(0, -0.03, 0);
	glScalef(0.2, 0.05, 0.2);
	glutSolidSphere(1.0, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glScalef(0.35, 0.35, 0.1);
	glutSolidTorus(0.5, 1, 20, 20);
	glPopMatrix();

	unsigned int texture;
	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// load and generate the texture

	int width, height, nrChannels;

	unsigned char* data = stbi_load("container.jpo”, &width, &height, &nrChannels, 0");
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load texture" << std::endl;

	}
	Stbi_image_free(data);

}
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-2, 5, 11, 0, 0, 0, 0, 1, 0);
	//gluLookAt(0,10, 0, 0, 0, 0, 0, 0, -1);


	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, green);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, green);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 10);


	glPushMatrix();
	glTranslatef(-1, -0.2, -1);
	glScalef(0.5, 0.7, 0.9);
	cadeira();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -0.2, -1);
	glScalef(0.5, 0.7, 0.9);
	cadeira();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, -0.2, 3);
	glScalef(0.5, 0.7, 0.9);
	glRotatef(180, 0, 1, 0);
	cadeira();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -0.2, 3);
	glScalef(0.5, 0.7, 0.9);
	glRotatef(180, 0, 1, 0);
	cadeira();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, -0.2, 3);
	glScalef(0.5, 0.7, 0.9);
	glRotatef(180, 0, 1, 0);
	cadeira();
	glPopMatrix();

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, marrom);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, marrom);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 10);

	glPushMatrix();
	glTranslatef(-1.4, -1.4, -0.9);
	pemesa();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.4, -1.4, -0.9);
	pemesa();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.4, -1.4, 0.9);
	pemesa();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.4, -1.4, 0.9);
	pemesa();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.4, 0.1);
	glScalef(4, 0.1, 3);
	glutSolidCube(1);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_AMBIENT, cinza);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cinza);
	glMaterialf(GL_FRONT, GL_SHININESS, 30);

	glPushMatrix();
	glTranslatef(-0.9, 0, -0.5);
	prato();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.9, 0, 0.7);
	prato();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.9, 0, 0.7);
	prato();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.9, 0, -0.5);
	prato();
	glPopMatrix();

	glFlush();
}
void reshape(GLint w, GLint h) {
	glViewport(0, 0, w, h);
	GLfloat aspect = GLfloat(w) / GLfloat(h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30, aspect, 0.1, 40);


}
void init() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glLightfv(GL_LIGHT0, GL_AMBIENT, black);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	glLightfv(GL_LIGHT0, GL_POSITION, direction);


	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_NORMALIZE);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}
