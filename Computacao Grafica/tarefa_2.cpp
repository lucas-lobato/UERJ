#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265


void init(void);
void display(void);
void drawDisk(double radius);
void drawSun(void);
void drawGarden(void);
void drawStreet(void);
void drawMontain(void);
void drawWindTurbine(void);
void drawPropellers(void);
void drawTurbinesPropellers(void);
void drawCar(void);
void drawSquare(void);
void drawWheel(void);


void init(void){
    glClearColor(0.8, 0.9, 1, 1.0);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-1, 1, -1, 1, -1, 1);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(0.75,0.75,0);
    drawSun();
    glPopMatrix();

    glPushMatrix();
    drawGarden();
    glPopMatrix();

    glPushMatrix();
    drawStreet();
    glPopMatrix();

    glPushMatrix();
    drawMontain();
    glPopMatrix();

    drawTurbinesPropellers();

    glPushMatrix();
    glTranslatef(-0.8,-0.3,0);
    drawCar();
    glPopMatrix();

    glFlush();
}

void keyboard( unsigned char key, int x, int y ){
    GLfloat colors[][3] = { { 0.0, 0.0, 0.0}, {1.0, 1.0, 1.0} };
    static int back;
    switch (key) {
    case ' ':
        back ^= 1;
        glClearColor(colors[back][0], colors[back][1], colors[back][2], 1.0);
        glutPostRedisplay();
    }
    display();
}


void drawDisk(double radius){
    int d;
    glBegin(GL_POLYGON);
    for(d=0; d<32; d++){
        double angle = ((2 * PI)/32)*d;
        glVertex2d(radius*cos(angle), radius*sin(angle));
    }
    glEnd();
}


void drawSun(){
    int i;
    glColor3f(1,1,0);
    for(i=0; i<13; i++){
        glRotatef(360/13, 0, 0, 1);
        glBegin(GL_LINES);
        glVertex2f(0.05, 0.05);
        glVertex2f(0.10, 0.125);
        glEnd();
    }
    drawDisk(0.10);
}

void drawGarden(){
    glBegin(GL_QUADS);
    glColor3f(0.1,0.7,0.1);
    glVertex3f(-1,-0.850,0);
    glVertex3f(1,-0.850,0);
    glVertex3f(1,-1,0);
    glVertex3f(-1,-1,0);
    glEnd();
}


void drawStreet(){
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-1,-0.650,0);
    glVertex3f(1,-0.650,0);
    glVertex3f(1,-0.850,0);
    glVertex3f(-1,-0.850,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-1,-0.745,0);
    glVertex3f(1,-0.745,0);
    glVertex3f(1,-0.755,0);
    glVertex3f(-1,-0.755,0);
    glEnd();
}


void drawMontain(){
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.7,0.1);
    glVertex3f(-1,-0.550,0);
    glVertex3f(-0.650,-0.200,0);
    glVertex3f(-0.200,-0.600,0);
    glVertex3f(-0.100,0,0);
    glVertex3f(0.500,-0.500,0);
    glVertex3f(0.750,-0.350,0);
    glVertex3f(1,-0.550,0);
    glVertex3f(1,-0.650,0);
    glVertex3f(-1,-0.650,0);
    glEnd();
}


void drawWindTurbine(){
    glBegin(GL_QUADS);
    glColor3f(0.25,0.25,0.25);
    glVertex3f(-0.360,-0.260,0);
    glVertex3f(-0.340,-0.260,0);
    glVertex3f(-0.340, 0.400,0);
    glVertex3f(-0.360, 0.400,0);
    glEnd();
}


void drawPropellers(){
    glColor3f(1,0.1,0.1);
    for(int i=0; i<4; i++){
        glRotatef(360/4, 0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.03, 0.08, 0.0);
        glVertex3f(0.0, 0.20, 0.0);
        glVertex3f(-0.03, 0.08, 0.0);
        glEnd();
    }
}


void drawTurbinesPropellers(){
    glPushMatrix();
    glTranslatef(-0.3,-0.1,0);
    drawWindTurbine();
    glPopMatrix();

    glPushMatrix();
    glRotatef(20, 0, 0, 1);
    glTranslatef(-0.51,0.50,0);
    drawPropellers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2,0.1,0);
    drawWindTurbine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.15,0.50,0);
    glRotatef(20, 0, 0, 1);
    drawPropellers();
    glPopMatrix();

    
    glPushMatrix();
    glTranslatef(1.0,-0.2,0);
    drawWindTurbine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.65,0.2,0);
    glRotatef(20, 0, 0, 1);
    drawPropellers();
    glPopMatrix();
}


void drawCar(){
    glPushMatrix();
    glTranslatef(0.60,-0.37,0);
    drawWheel();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.80,-0.37,0);
    drawWheel();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.65,0.2,0);
    drawSquare();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.65,0.05,0);
    glScalef(0.5,0.5,0);
    drawSquare();
    glPopMatrix();
}


void drawWheel(){
    glPushMatrix();
    glColor3f(0,0,0);
    drawDisk(0.06);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    drawDisk(0.045);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    drawDisk(0.02);
    glPopMatrix();

    glColor3f(0,0,0);
    for(int i=0; i<13; i++){
        glRotatef(360/13, 0, 0, 1);
        glBegin(GL_LINES);
        glVertex2f(0.01, 0.01);
        glVertex2f(0.045, 0.045);
        glEnd();
    }

}


void drawSquare(){
    glBegin(GL_QUADS);
    glColor3f(0.9,0.1,0.1);
    glVertex3f(-0.150,-0.550,0);
    glVertex3f(0.250,-0.550,0);
    glVertex3f(0.250,-0.400,0);
    glVertex3f(-0.150,-0.400,0);
    glEnd();
}


int main(int argc, char** argv){

    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize (500, 500);
    glutInitWindowPosition (300, 100);

    glutCreateWindow ("tarefa_2");

    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);


    glutMainLoop();

    return 0;
}