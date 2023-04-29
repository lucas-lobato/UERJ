#include <GL/glut.h>


void roda(void);
void esfera(void);
void aste(void);
void lines(void);


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);

    glPushMatrix();
    glTranslated(-2.0,-2.0,0);
    roda();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0, -2.0, 0.0);
    roda();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0, -2.0, 0.0);
    esfera();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0, -2.0, 0.0);
    esfera();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -2.0, 0.0);
    glScalef(4.0,0.1,0.1);
    aste();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0, -2.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    lines();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0, -2.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    lines();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0, -2.0, -1.0);
    glScalef(0.1,0.1,2.0);
    aste();
    glPopMatrix();

    glPopMatrix();
    glFlush();
}


void roda(){
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glutSolidTorus(0.150, 0.80, 20, 40);
}


void esfera(){
    glutSolidSphere(0.2, 30, 30);
}


void aste(){
    glutSolidCube(1.0);
}

void lines(){
    int i;
    glColor3f(1,1,0);
    for(i=0; i<13; i++){
        glRotatef(360/13, 0, 0, 1);
        glBegin(GL_LINES);
        glVertex3f(0.1, 0.1, 0);
        glVertex3f(0.6, 0.6, 0);
        glEnd();
    }
}

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    GLfloat aspect = GLfloat(w) / GLfloat(h);
    glLoadIdentity();

    if (w <= h) {
    glOrtho(-2.5, 2.5, -2.5/aspect, 2.5/aspect, -10.0, 10.0);
    } else {
    glOrtho(-2.5*aspect, 2.5*aspect, -2.5, 2.5, -10.0, 10.0);
    }
}


void init() {

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluLookAt(0, 2.5, 0, 0,0,0, 0, 0, -1);


    GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
    GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat direction[] = { 0.0, -10.0, 0.0, 1.0 };
    GLfloat direction1[] = { 0.0, 10.0, 0.0, 1.0 };

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

    glEnable(GL_LIGHTING);             
    glEnable(GL_LIGHT0);                  
    glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);              

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Patinete");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}