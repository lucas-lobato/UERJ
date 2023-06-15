#include "Primitivas.hpp"


void Primitivas::drawTriangle() {
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.150, 0.150, 0);
    glVertex3f(0.250, 0.250, 0);
    glVertex3f(0.350, 0.150, 0);
    glEnd();
    glPopMatrix();
}

void Primitivas::drawPolygon() {
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.05, 0.5, 0.0);
    glVertex3f(0, 0, 0);
    glVertex3f(0.1, 0.1, 0);
    glVertex3f(0.4, 0.1, 0);
    glVertex3f(0.4, 0, 0);
    glEnd();
    glPopMatrix();
}

void Primitivas::drawSquare() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(-0.150, -0.550, 0);
    glVertex3f(0.250, -0.550, 0);
    glVertex3f(0.250, -0.400, 0);
    glVertex3f(-0.150, -0.400, 0);
    glEnd();
    glPopMatrix();
}

void Primitivas::drawDisk(double radius) {
    int d;
    glBegin(GL_POLYGON);
    for (d = 0; d < 32; d++) {
        double angle = ((2 * PI) / 32) * d;
        glVertex2d(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}
