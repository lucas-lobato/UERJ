#define STB_IMAGE_IMPLEMENTATION
#include "Jogo.hpp"
#include "SkyBox.hpp"


using namespace std;

Jogo jogo;
SkyBox skybox;


void init(void) {
    glClearColor(0.8, 0.9, 1, 1.0);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluPerspective(90, 2, 0.1, 15);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    //skybox.loadSkyboxTextures();
}

// atualiza o frame
void refresh() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, 2, 0.1, 15);

}


// redimensiona a tela
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    refresh();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}

// display
void display() {

    // termina o jogo o jogo
    if (jogo.gameOver) {
        system("pause");
        exit(0);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    refresh();
    gluLookAt(0.1 + jogo.characterPosX, 0.1, 1, 0 + jogo.characterPosX, 0, 0, 0, 1, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glPushMatrix();
    jogo.drawCenario();
    glPopMatrix();

    glPushMatrix();
    glTranslatef((GLfloat)jogo.characterPosX, 0, (GLfloat)jogo.characterPosZ);
    glTranslatef(-0.9, -0.5, 0);
    glRotatef(jogo.zRotation,0,1,0);
    glScalef(0.05, 0.05, 0.05);
    jogo.drawCharacter();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6 + jogo.missilMovement, -0.55, 0);
    jogo.drawMissile();
    glPopMatrix();

    glPushMatrix();
    jogo.colisionCoinCheck();
    jogo.drawCoins();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.5 + jogo.characterPosX,0.2,0);
    jogo.drawScore();
    glPopMatrix();

    glPushMatrix();
    //skybox.drawSkybox();
    glPopMatrix();

    // verifica se o jogador perdeu
    if (jogo.colisionMissileCheck()) {
        glPushMatrix();
        glTranslatef(0.5 + jogo.characterPosX,-1,0);
        jogo.drawGameOverScreen();
        glPopMatrix();
        jogo.gameOver = true;
    }

    glFlush();
}

// Pega a açao do teclado
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'd':
        if (jogo.colisionBoxCheckD()) {
            jogo.characterMovementX(0.01);
            jogo.update();
            jogo.zRotation = 90;
            glutPostRedisplay();
        }
        break;
    case 'a':
        if (jogo.colisionBoxCheckA()) {
            jogo.characterMovementX(-0.01);
            jogo.update();
            jogo.zRotation = 90;
            glutPostRedisplay();
        }
        break;
    case 'w':
        if (jogo.colisionBoxCheckW()) {
            jogo.characterMovementZ(-0.01);
            jogo.update();
            jogo.zRotation = 180;
            glutPostRedisplay();
        }
        break;
    case 's':
        if (jogo.colisionBoxCheckS()) {
            jogo.characterMovementZ(0.01);
            jogo.update();
            glutPostRedisplay();
            jogo.zRotation = 180;
        }
        break;
    default:
        break;
    }
}

// Atualiza a posição das nuvens com o passar do tempo
void updateClouds(int value) {
    jogo.cloudMovement = jogo.cloudMovement - 0.005;
    if (jogo.cloudMovement < -2) {
        jogo.cloudMovement = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(120, updateClouds, 0);
}

// Atualiza a posição do missil com o passar do tempo
void updateMissil(int value) {
    jogo.missilMovement = jogo.missilMovement - 0.01;
    jogo.missilLocation = jogo.missilLocation + 0.01;
    if (jogo.missilLocation < 9.01 && jogo.missilLocation > 8.99) {
        jogo.missilLocation = 0;
    }
    if (jogo.missilMovement < -9) {
        jogo.missilMovement = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(30, updateMissil, 0);
}

// main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(jogo.width, jogo.height);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("ATAQUE DO MISSIL");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, updateClouds, 0);
    glutTimerFunc(0, updateMissil, 0);
    glutMainLoop();
    return 0;
}