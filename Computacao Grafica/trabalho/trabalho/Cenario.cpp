#include "Cenario.hpp"

// Desesnha todo o cenario
void Cenario::drawCenario() {
    glPushMatrix();
    drawScene();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,0,0);
    drawScene();
    glPopMatrix();
}

// Desenha parte do cenario
void Cenario::drawScene() {
    glPushMatrix();
    glTranslatef(cloudMovement,0,0);
    drawClouds();
    glPopMatrix();

    glPushMatrix();
    drawGarden();
    glPopMatrix();

    glPushMatrix();
    drawCaixas();
    glPopMatrix();
}

// Desenha o jardim
void Cenario::drawGarden() {
    glPushMatrix();
    glColor3f(0.05, 0.5, 0.0);
    glTranslatef(-1, -0.75, 0.0);
    glScalef(5, 0.1, 0.5);
    drawCube();
    glPopMatrix();
}

// Desenha as nuvens
void Cenario::drawClouds() {
    glPushMatrix();
    glTranslatef(-3, 0.1, 0);
    for (int i = 0; i <= 20; i++) {
        glTranslatef(1, 0, 0);
        drawCloud();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.5, 0.6, 0);
    for (int i = 0; i <= 20; i++) {
        glTranslatef(1, 0, 0);
        drawCloud();
    }
    glPopMatrix();
}

// Desenha uma nuvem
void Cenario::drawCloud() {
    glPushMatrix();
    glColor3f(1, 1, 1);
    drawSfere();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0.02, 0, 0);
    drawSfere();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0.04, 0, 0);
    drawSfere();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0.01, 0.03, 0);
    drawSfere();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0.03, 0.03, 0);
    drawSfere();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0.02, 0.055, 0);
    drawSfere();
    glPopMatrix();
}

// Desenha uma moeda
void Cenario::drawCoin() {
    // Desenhar o aro externo da moeda
    glColor3f(0.72, 0.52, 0.04); // Cor do aro (dourado escuro)
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++)
    {
        float theta = i * 3.14159 / 180.0;
        float x = 0.5 * cos(theta); // Raio externo da moeda é 0.5
        float y = 0.5 * sin(theta);
        glVertex3f(x, y, 0.0);
    }
    glEnd();

    // Desenhar o círculo interno da moeda
    glColor3f(1, 0.84, 0); // Cor do círculo (dourado claro)
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float theta = i * 3.14159 / 180.0;
        float x = 0.4 * cos(theta); // Raio interno da moeda é 0.4
        float y = 0.4 * sin(theta);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
}

// Desenha uma caixa
void Cenario::drawCaixa() {
    glPushMatrix();
    glColor3f(0.87, 0.72, 0.53);
    glTranslatef(0, -0.60, 0);
    glScalef(0.2, 0.2, 0.1);
    drawCube();
    glPopMatrix();
}

// Desenha todas as caixas
void Cenario::drawCaixas() {
    glPushMatrix();
    glTranslatef(-3, 0, 0.2);
    for (int i = 0; i <= 4; i++) {
        glTranslatef(1 ,0 ,0);
        drawCaixa();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.5, 0, -0.2);
    for (int i = 0; i <= 4; i++) {
        glTranslatef(1, 0, 0);
        drawCaixa();
    }
    glPopMatrix();
}