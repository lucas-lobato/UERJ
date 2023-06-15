#include <GL/glut.h>


void banco_e_encosto(void);
void cadeira(void);
void pernas(void);
void cruzes(void);


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();

    glEnable(GL_LIGHT0);

    glPushMatrix();
    cadeira();
    glPopMatrix();

    glDisable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glPushMatrix();
    glTranslatef(-1, 0.0, 0.0);
    
    glPopMatrix();

    glDisable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    glPushMatrix();
    glTranslatef(0.0, 1.0, -5.5);
    
    glPopMatrix();

    glDisable(GL_LIGHT2);
    glEnable(GL_LIGHT3);

    glPushMatrix();
    glTranslatef(0.0, -1.0, 6);
    
    glPopMatrix();

    glDisable(GL_LIGHT3);


    glPopMatrix();
    glFlush();
}


void cadeira(){
    glPushMatrix();
    banco_e_encosto();
    glPopMatrix();

    glPushMatrix();
    pernas();
    glPopMatrix();
    
    glPushMatrix();
    cruzes();
    glPopMatrix();
}


void banco_e_encosto(){
    glPushMatrix();
    glScalef(0.5,5,5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,-2.2,0);
    glScalef(4,0.5,5);
    glutSolidCube(1);
    glPopMatrix();
}


void pernas(){
    glPushMatrix();
    glTranslatef(0,-4,2.2);
    glScalef(0.5,-3,0.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(0.5,-3,0.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(0.5,-3,0.5);
    glutSolidCube(1);
    glPopMatrix();
}


void cruzes(){

}


void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    GLfloat aspect = GLfloat(w) / GLfloat(h);
    glLoadIdentity();
    gluPerspective(90,aspect, 0.1, 15);
    gluLookAt(10,0,10,0,0,0,0,1,0);
}


void init() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat pink[] = { 1.0, 0.5, 1.0, 1.0 };
    GLfloat pink2[] = { 0.5, 1.0, 0.5, 1.0 };
    GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
    GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat direction[] = { 0.0, 0.0, 10.0, 1.0 };
    GLfloat direction1[] = { 0.0,0.0, 10.0, 1.0 };

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cyan);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 30);

    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, yellow);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    glLightfv(GL_LIGHT0, GL_POSITION, direction);

    glLightfv(GL_LIGHT1, GL_AMBIENT, black);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT1, GL_SPECULAR, white);
    glLightfv(GL_LIGHT1, GL_POSITION, direction1);

    glLightfv(GL_LIGHT2, GL_AMBIENT, black);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, pink);
    glLightfv(GL_LIGHT2, GL_SPECULAR, white);
    glLightfv(GL_LIGHT2, GL_POSITION, direction1);

    glLightfv(GL_LIGHT3, GL_AMBIENT, black);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, pink2);
    glLightfv(GL_LIGHT3, GL_SPECULAR, white);
    glLightfv(GL_LIGHT3, GL_POSITION, direction1);

    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

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