#include <GL/glut.h>
#include <math.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Cenario.hpp"
#include "Personagem.hpp"

Cenario cenario_main;
Personagem personagem;

using namespace std;

void init(void);
void display(void);


void init(void) {
    glClearColor(0.8, 0.9, 1, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (personagem.contador == 350) {
        cenario_main.scene1Replay = cenario_main.scene1Replay + 4;
    }

    if (personagem.contador == 550) {
        cenario_main.scene2Replay = cenario_main.scene2Replay + 4;
        personagem.contador = 150;
    }

    glPushMatrix();
    cenario_main.drawbackground();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0.25, 0);
    glScalef(0.75, 0.95, 0.0);
    cenario_main.drawSun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef((GLfloat)cenario_main.scene1Replay, 0, 0);
    glTranslatef((GLfloat)cenario_main.displayMovement, 0, 0);
    cenario_main.drawScene();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, 0, 0);
    glTranslatef((GLfloat)cenario_main.scene2Replay, 0, 0);
    glTranslatef((GLfloat)cenario_main.displayMovement, 0, 0);
    cenario_main.drawScene();
    glPopMatrix();

    glPushMatrix();
    glTranslatef((GLfloat)personagem.characterPosX, (GLfloat)personagem.characterPosY, 0);
    glTranslatef(-0.9, -0.85, 0);
    glScalef(0.5, 0.5, 0);
    personagem.drawCharacter();
    glPopMatrix();

    Sleep(10);
    glFlush();
}


void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'd':
        personagem.characterMovement(0.01);
        break;
    case 'a':
        personagem.characterMovement(-0.01);
        break;
    case ' ':
        personagem.jumping();
        display();
        break;
    default:
        break;
    }
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("TRABALHO");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}