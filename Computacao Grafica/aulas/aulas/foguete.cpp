#include <GL/glut.h>


void DesenhaFoguete();


void Bico(){
    glBegin(GL_TRIANGLES);
    glColor3f(0,1,0);
    glVertex3f(3.0,6.0,0);
    glVertex3f(4.0,8.0,0);
    glVertex3f(5.0,6.0,0);
    glEnd();
}

void Corpo(){
    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(3.0,1.0,0);
    glVertex3f(5.0,1.0,0);
    glVertex3f(5.0,6.0,0);
    glVertex3f(3.0,6.0,0);
    glEnd();
}

void AsaEsquerda(){
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex3f(1.5,1.0,0);
    glVertex3f(3.0,1.0,0);
    glVertex3f(3.0,3.0,0);
    glEnd();
}

void AsaDireita(){
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex3f(5.0,1.0,0);
    glVertex3f(6.5,1.0,0);
    glVertex3f(5.0,3.0,0);
    glEnd();
}

void DesenhaFoguete(void){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    Bico();
    Corpo();
    AsaEsquerda();
    AsaDireita();
    glFlush();
}