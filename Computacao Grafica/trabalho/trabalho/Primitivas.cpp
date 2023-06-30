#include "Primitivas.hpp"


// Desenha uma esfera
void Primitivas::drawSfere() {
    glPushMatrix();
    glScalef(0.05,0.05,0.05);
    glutSolidSphere(0.5, 30, 30);
    glPopMatrix();
        
}

// Desenha um cubo
void Primitivas::drawCube() {
    glPushMatrix();
    glutSolidCube(1);
    glPopMatrix();
}

// Desenha um cone
void Primitivas::drawCone() {
    const float radius = 1.0f; // Raio da base do cone
    const float height = 2.0f; // Altura do cone
    const int numSegments = 50; // Número de segmentos para a base do cone

    // Desenha a base do cone
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 0.0f); // Centro da base
    for (int i = 0; i <= numSegments; ++i) {
        float theta = (2.0f * 3.1415926f * float(i)) / float(numSegments);
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();

    // Desenha a lateral do cone
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, height); // Ponto no vértice do cone
    for (int i = 0; i <= numSegments; ++i) {
        float theta = (2.0f * 3.1415926f * float(i)) / float(numSegments);
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
}

// Desenha um cilindro
void Primitivas::drawCilinder() {
    glPushMatrix();
    GLUquadricObj* cylinder = gluNewQuadric();
    gluQuadricDrawStyle(cylinder, GLU_FILL);
    gluCylinder(cylinder, 0.05f, 0.05f, 0.1f, 20, 20);
    gluDeleteQuadric(cylinder);
    glPopMatrix();
}

// Desenha torus(rosquinha)
void Primitivas::drawTorus() {
    glPushMatrix();
    glutSolidTorus(0.5, 1.0, 30, 30);
    glPopMatrix();
}