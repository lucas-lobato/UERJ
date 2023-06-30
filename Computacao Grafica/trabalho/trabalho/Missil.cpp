#include "Missil.hpp"

void Missil::drawMissile() {
    // Corpo do míssil
    glPushMatrix();
    glTranslatef(-0.1, 0, 0);
    glRotatef(90,0,1,0);
    glScalef(1,1,1.5);
    drawCilinder();
    glPopMatrix();

    // Ponta do míssil
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f); // Vermelho
    glTranslatef(-0.1f, 0.0f, 0.0f); // Posiciona a ponta no topo do corpo
    glRotatef(270,0,1,0);
    glScalef(0.05, 0.05, 0.05);
    drawCone(); // Desenha um cone
    glPopMatrix();

    // Trazeira do missil
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f); // Vermelho
    glTranslatef(0.065,0,0);
    glRotatef(90,0,1,0);
    glScalef(0.04, 0.04, 0.04);
    drawTorus();
    glPopMatrix();
}