#include "Cenario.hpp"
#include "Primitivas.hpp"

Primitivas primitiva;

void Cenario::drawScene() {
    glPushMatrix();
    glTranslatef((GLfloat)cloudMove, 0, 0);
    drawClouds();
    glPopMatrix();

    glPushMatrix();
    drawTurbines();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.85, 1.65, 0);
    glScalef(1.2, 4.5, 0);
    drawMontain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, 0.85, 0);
    glScalef(0.9, 3, 0);
    drawMontain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.65, -0.71, 0);
    glScalef(0.75, 1.4, 0);
    drawHills();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.425, 0.85, 0);
    glScalef(2, 2, 0);
    drawHouse();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0.87, 0);
    glScalef(0.8, 3, 0);
    drawMontain();
    glPopMatrix();

    glPushMatrix();
    drawGarden();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, 0.71, 0);
    glScalef(2, 2, 0);
    drawHouse();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.7, 0.715, 0);
    glScalef(2, 2, 0);
    drawHouse();
    glPopMatrix();

    glPushMatrix();
    drawTrees();
    glPopMatrix();

    glPushMatrix();
    drawCoins();
    glPopMatrix();
}

void Cenario::drawGarden() {
    glPushMatrix();
    glColor3f(0.05, 0.5, 0.0);
    glTranslatef(-0.25, -0.175, 0.0);
    glScalef(5.0, 1.5, 0.0);
    primitiva.drawSquare();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1, 0.7, 0.2);
    glTranslatef(-0.25, -0.50, 0.0);
    glScalef(5.0, 0.5, 0.0);
    primitiva.drawSquare();
    glPopMatrix();
}

void Cenario::drawbackground() {
    glPushMatrix();
    glColor3f(0.3, 0.05, 0.6);
    glScalef(5.0, 12.40, 0.0);
    glTranslatef(-0.05, 0.481, 0.0);
    primitiva.drawSquare();
    glPopMatrix();
}


void Cenario::drawMontain() {
    glPushMatrix();
    glColor3f(0.45, 0.45, 0.45);
    glTranslatef(-0.25, -0.75, 0.0);
    glScalef(2.0, 1.5, 0.0);
    primitiva.drawTriangle();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
    glTranslatef(0.205, -0.36, 0);
    glRotatef(35, 0, 0, 1);
    glScalef(0.1, 0.1, 0);
    primitiva.drawSquare();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
    glTranslatef(0.238, -0.435, 0);
    glRotatef(145, 0, 0, 1);
    glScalef(0.1, 0.1, 0);
    primitiva.drawSquare();
    glPopMatrix();
}


void Cenario::drawWindTurbine() {
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.25, 0.25);
    glVertex3f(-0.360, -0.260, 0);
    glVertex3f(-0.340, -0.260, 0);
    glVertex3f(-0.348, 0.335, 0);
    glVertex3f(-0.352, 0.335, 0);
    glEnd();
}


void Cenario::drawPropellers() {
    glPushMatrix();
    glColor3f(0.05, 0, 0.4);
    primitiva.drawTriangle();
    glPopMatrix();
}


void Cenario::drawTurbines() {
    glPushMatrix();
    drawTurbinesPropellers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0, 0);
    drawTurbinesPropellers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, 0, 0);
    drawTurbinesPropellers();
    glPopMatrix();
}


void Cenario::drawTurbinesPropellers() {
    glPushMatrix();
    glTranslatef(-0.5, -0.45, 0);
    drawWindTurbine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.95, -0.62, 0);
    glRotatef(350, 0, 0, 1);
    glScalef(0.05, 3.5, 0);
    drawPropellers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.51, 0.05, 0);
    glRotatef(120, 0, 0, 1);
    glScalef(0.1, 2.5, 0);
    drawPropellers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.12, 0.15, 0);
    glRotatef(230, 0, 0, 1);
    glScalef(0.1, 2.5, 0);
    drawPropellers();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.05, 0, 0.4);
    glTranslatef(-0.85, -0.12, 0);
    glScalef(0.15, 0.3, 0);
    primitiva.drawDisk(0.10);
    glPopMatrix();
}


void Cenario::drawHouse() {
    glPushMatrix();
    glColor3f(0.6, 0.8, 1);
    glTranslatef(-0.5, -0.570, 0);
    glScalef(0.1, 0.25, 0);
    primitiva.drawSquare(); //garagem
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0.2);
    glTranslatef(-0.498, -0.652, 0);
    glScalef(0.05, 0.1, 0);
    primitiva.drawSquare(); //portao da garagem
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2, 1, 1);
    glTranslatef(-0.445, -0.433, 0);
    glScalef(0.2, 0.5, 0);
    primitiva.drawSquare(); //casa
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(-0.420, -0.545, 0);
    glScalef(0.03, 0.3, 0);
    primitiva.drawSquare(); //porta
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2, 0, 0.09);
    glTranslatef(-0.460, -0.620, 0);
    glScalef(0.02, 0.1, 0);
    primitiva.drawSquare(); //janelas
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2, 0, 0.09);
    glTranslatef(-0.450, -0.620, 0);
    glScalef(0.02, 0.1, 0);
    primitiva.drawSquare(); //janelas
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2, 0, 0.09);
    glTranslatef(-0.460, -0.640, 0);
    glScalef(0.02, 0.1, 0);
    primitiva.drawSquare(); //janelas
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2, 0, 0.09);
    glTranslatef(-0.450, -0.640, 0);
    glScalef(0.02, 0.1, 0);
    primitiva.drawSquare(); //janelas
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(-0.480, -0.635, 0);
    glScalef(0.3, 0.3, 0);
    drawTelhadoCasa(); //telhado casa
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(-0.520, -0.670, 0);
    glScalef(0.15, 0.25, 0);
    drawTelhadoGaragem(); //telhado garagem
    glPopMatrix();
}


void Cenario::drawTelhadoCasa() {
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0.1, 0);
    glVertex3f(0.3, 0.05, 0);
    glVertex3f(0.3, 0, 0);
    glEnd();
    glPopMatrix();
}


void Cenario::drawTelhadoGaragem() {
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(0.1, 0.1, 0);
    glVertex3f(0.3, 0.1, 0);
    glVertex3f(0.3, 0, 0);
    glEnd();
    glPopMatrix();
}


void Cenario::drawHills() {
    glPushMatrix();
    primitiva.drawPolygon();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.05, 0.5, 0.0);
    glTranslatef(0.5, 0, 0);
    primitiva.drawDisk(0.10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.05, 0.5, 0.0);
    glTranslatef(0.7, 0.03, 0);
    glScalef(1.5, 1.5, 0);
    primitiva.drawDisk(0.10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.05, 0.5, 0.0);
    glTranslatef(0.9, 0, 0);
    primitiva.drawDisk(0.10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.25, 0, 0);
    primitiva.drawPolygon();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.05, 0.5, 0.0);
    glTranslatef(2.08, 0, 0);
    glScalef(0.75, 0.75, 0);
    primitiva.drawDisk(0.10);
    glPopMatrix();
}


void Cenario::drawTrees() {
    glPushMatrix();
    drawRoundTrees();
    glPopMatrix();

    glPushMatrix();
    drawTriangleTrees();
    glPopMatrix();

    glPushMatrix();
    drawCircleTrees();
    glPopMatrix();
}


void Cenario::drawRoundTrees() {
    glPushMatrix();
    drawRoundTree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, 0.235, 0);
    drawRoundTree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.37, 0, 0);
    drawRoundTree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.7, 0, 0);
    drawRoundTree();
    glPopMatrix();
}


void Cenario::drawRoundTree() {
    glPushMatrix();
    glColor3f(0.35, 0.23, 0);
    glTranslatef(-0.75, -0.01, 0);
    glScalef(0.015, 1.25, 0);
    primitiva.drawSquare();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.05, 0.5, 0.0);
    glTranslatef(-0.75, -0.5, 0);
    glScalef(0.25, 0.4, 0);
    primitiva.drawDisk(0.10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.05, 0.5, 0.0);
    glTranslatef(-0.75, -0.46, 0);
    glScalef(0.25, 0.4, 0);
    primitiva.drawDisk(0.10);
    glPopMatrix();
}


void Cenario::drawTriangleTrees() {
    glPushMatrix();
    drawTriangleTree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1, 0, 0);
    drawTriangleTree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.78, -0.05, 0);
    drawTriangleTree();
    glPopMatrix();
}


void Cenario::drawTriangleTree() {
    glPushMatrix();
    glColor3f(0.35, 0.23, 0);
    glTranslatef(-0.45, 0.11, 0);
    glScalef(0.015, 1.25, 0);
    primitiva.drawSquare();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.05, 0.5, 0.0);
    glTranslatef(-0.512, -0.6, 0);
    glScalef(0.25, 1.25, 0);
    primitiva.drawTriangle();
    glPopMatrix();
}


void Cenario::drawCircleTrees() {
    glPushMatrix();
    glTranslatef(0, -0.01, 0);
    drawCircleTree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, -0.01, 0);
    drawCircleTree();
    glPopMatrix();
}


void Cenario::drawCircleTree() {
    glPushMatrix();
    glColor3f(0.35, 0.23, 0);
    glScalef(0.015, 1.25, 0);
    primitiva.drawSquare();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.05, 0.5, 0.0);
    glTranslatef(-0.01, -0.5, 0);
    glScalef(0.150, 0.2, 0);
    primitiva.drawDisk(0.10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.05, 0.5, 0.0);
    glTranslatef(0.0, -0.480, 0);
    glScalef(0.150, 0.2, 0);
    primitiva.drawDisk(0.10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.05, 0.5, 0.0);
    glTranslatef(0.01, -0.5, 0);
    glScalef(0.150, 0.2, 0);
    primitiva.drawDisk(0.10);
    glPopMatrix();
}

void Cenario::drawClouds() {
    glPushMatrix();
    glTranslatef(0, 0.1, 0);
    drawCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 0.4, 0);
    drawCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, 0.6, 0);
    drawCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7, 0.2, 0);
    drawCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.9, 0.5, 0);
    drawCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2, 0.4, 0);
    drawCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4, 0.6, 0);
    drawCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7, 0.2, 0);
    drawCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.9, 0.5, 0);
    drawCloud();
    glPopMatrix();
}


void Cenario::drawCloud() {
    glPushMatrix();
    glColor3f(1, 1, 1);
    primitiva.drawDisk(0.02);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0.02, 0, 0);
    primitiva.drawDisk(0.02);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0.04, 0, 0);
    primitiva.drawDisk(0.02);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0.01, 0.03, 0);
    primitiva.drawDisk(0.02);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0.03, 0.03, 0);
    primitiva.drawDisk(0.02);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0.02, 0.055, 0);
    primitiva.drawDisk(0.02);
    glPopMatrix();
}

void Cenario::drawCoin() {
    glPushMatrix();
    glColor3f(0.7, 0.7, 0);
    glScalef(0.5, 1.5, 0);
    primitiva.drawDisk(0.02);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 0);
    glScalef(0.5, 1.5, 0);
    primitiva.drawDisk(0.01);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.7, 0.7, 0);
    glTranslatef(0, 0.045, 0);
    glScalef(0.01, 0.1, 0);
    primitiva.drawSquare();
    glPopMatrix();
}

void Cenario::drawCoins() {
    if (drawingCoin == true) {
        glPushMatrix();
        glTranslatef(-0.7, -0.6, 0);
        drawCoin();
        glPopMatrix();
    }
}

void Cenario::drawSun() {
    int i;
    glColor3f(1, 1, 0);
    for (i = 0; i < 13; i++) {
        glRotatef(360 / 13, 0, 0, 1);
        glBegin(GL_LINES);
        glVertex2f(0.05, 0.05);
        glVertex2f(0.10, 0.125);
        glEnd();
    }
    primitiva.drawDisk(0.10);
}