#include "Personagem.hpp"
#include "Primitivas.hpp"
#include "Cenario.hpp"


Primitivas primitivas;
Cenario cenario;


void Personagem::characterMovement(float movement) {
    characterPosX = characterPosX + movement;
    if (movement < 0) {
        contador = contador - 2;
    }
    if (characterPosX >= 1.5) {
        cenario.displayMovement = cenario.displayMovement - movement;
        characterPosX = characterPosX - movement;
    }
    if (characterPosX <= -0.05) {
        characterPosX = characterPosX - movement;
    }
    if (contador == 19) {
        cenario.drawingCoin = false;
    }
    contador = contador + 1;
    glutPostRedisplay();
}


void Personagem::drawCharacter()
{
    glColor3f(1.0, 0.0, 0.0);

    //head
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    primitivas.drawDisk(0.02);
    glPopMatrix();

    //Body
    glPushMatrix();
    glTranslatef(-0.002, 0.8, 0);
    glScalef(0.075, 0.8, 0);
    primitivas.drawSquare();
    glPopMatrix();

    //Left arm
    glPushMatrix();
    glTranslatef(-0.20, 0.34, 0);
    glRotatef(120, 0, 0, 1);
    glScalef(0.03, 0.4, 0);
    primitivas.drawSquare();
    glPopMatrix();

    //Right arm
    glPushMatrix();
    glTranslatef(0.20, 0.34, 0);
    glRotatef(240, 0, 0, 1);
    glScalef(0.03, 0.4, 0);
    primitivas.drawSquare();
    glPopMatrix();

    //Left leg
    glPushMatrix();
    glTranslatef(-0.110, 0.18, 0);
    glRotatef(150, 0, 0, 1);
    glScalef(0.03, 0.4, 0);
    primitivas.drawSquare();
    glPopMatrix();

    //Right leg
    glPushMatrix();
    glTranslatef(-0.076, 0.51, 0);
    glRotatef(30, 0, 0, 1);
    glScalef(0.03, 0.4, 0);
    primitivas.drawSquare();
    glPopMatrix();
}


void Personagem::jumping() {
    for (int i = 0; i <= 20; i++) {
        characterPosY = characterPosY + 0.01;
        glutPostRedisplay();
    }
    for (int i = 0; i <= 20; i++) {
        characterPosY = characterPosY - 0.01;
        glutPostRedisplay();
    }
}
