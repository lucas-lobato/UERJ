#include "jogo.hpp"

// verifica colisao com as caixas indo para a direita
bool Jogo::colisionBoxCheckD() {
    if (characterPosX > 0.24 && characterPosX < 0.26 && characterPosZ < -0.1) {
        return false;
    }
    else if (characterPosX > 1.24 && characterPosX < 1.26 && characterPosZ < -0.1) {
        return false;
    }
    else if (characterPosX > 2.24 && characterPosX < 2.26 && characterPosZ < -0.1) {
        return false;
    }
    else if (characterPosX > 3.24 && characterPosX < 3.26 && characterPosZ < -0.1) {
        return false;
    }
    else if (characterPosX > 0.74 && characterPosX < 0.76 && characterPosZ > 0.1) {
        return false;
    }
    else if (characterPosX > 1.74 && characterPosX < 1.76 && characterPosZ > 0.1) {
        return false;
    }
    else if (characterPosX > 2.74 && characterPosX < 2.76 && characterPosZ > 0.1) {
        return false;
    }
    else if (characterPosX > 3.74 && characterPosX < 3.76 && characterPosZ > 0.1) {
        return false;
    }
    else {
        return true;
    }
}

// verifica colisao com as caixas indo para a esquerda
bool Jogo::colisionBoxCheckA() {
    if (characterPosX > 0.55 && characterPosX < 0.57 && characterPosZ < -0.1) {
        return false;
    }
    else if (characterPosX > 1.55 && characterPosX < 1.57 && characterPosZ < -0.1) {
        return false;
    }
    else if (characterPosX > 2.55 && characterPosX < 2.57 && characterPosZ < -0.1) {
        return false;
    }
    else if (characterPosX > 3.55 && characterPosX < 3.57 && characterPosZ < -0.1) {
        return false;
    }
    else if (characterPosX > 0.04 && characterPosX < 0.06 && characterPosZ > 0.1) {
        return false;
    }
    else if (characterPosX > 1.04 && characterPosX < 1.06 && characterPosZ > 0.1) {
        return false;
    }
    else if (characterPosX > 2.04 && characterPosX < 2.06 && characterPosZ > 0.1) {
        return false;
    }
    else if (characterPosX > 3.04 && characterPosX < 3.06 && characterPosZ > 0.1) {
        return false;
    }
    else {
        return true;
    }
}


// verifica colisao com as caixas indo para cima
bool Jogo::colisionBoxCheckW() {
    if (characterPosX > 0.24 && characterPosX < 0.56 && characterPosZ < -0.09) {
        return false;
    }
    else if (characterPosX > 1.24 && characterPosX < 1.56 && characterPosZ < -0.09) {
        return false;
    }
    else if (characterPosX > 2.24 && characterPosX < 2.56 && characterPosZ < -0.09) {
        return false;
    }
    else if (characterPosX > 3.24 && characterPosX < 3.56 && characterPosZ < -0.09) {
        return false;
    }
    else {
        return true;
    }
}

// verifica colisao com as caixas indo para baixo
bool Jogo::colisionBoxCheckS() {
    if (characterPosX > -0.26 && characterPosX < 0.06 && characterPosZ > 0.09) {
        return false;
    }
    else if (characterPosX > 0.74 && characterPosX < 1.06 && characterPosZ > 0.09) {
        return false;
    }
    else if (characterPosX > 1.74 && characterPosX < 2.06 && characterPosZ > 0.09) {
        return false;
    }
    else if (characterPosX > 2.74 && characterPosX < 3.06 && characterPosZ > 0.09) {
        return false;
    }
    else if (characterPosX > 3.74 && characterPosX < 4.06 && characterPosZ > 0.09) {
        return false;
    }
    else {
        return true;
    }
}

// verifica colisao com o missil
bool Jogo::colisionMissileCheck() {
    if ((missilLocation + characterPosX > 6.64 && missilLocation + characterPosX < 6.66) && (characterPosZ < 0.1 && characterPosZ > -0.1)) {
        return true;
    }
    else {
        return false;
    }
}

// verifica se pegou moeda
void Jogo::colisionCoinCheck() {
    if ((characterPosX > 3.0 && characterPosX < 3.06) && (characterPosZ > -0.05 && characterPosZ < 0.05)) {
        drawingCoin = false;
        if (coletou == false) {
            pontuacao++;
            coletou = true;
        }
    }
}

// mostra a tela de game over
void Jogo::drawGameOverScreen() {

    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));

    // Configura a cor do texto como vermelho
    glColor3f(1, 0, 0);

    // Define a posição do texto
    glRasterPos3f(0.1, 650, 1);

    // Escreve o texto na tela
    const char* text = "GAME OVER";
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

// coloca moedas no jogo
void Jogo::drawCoins() {
    if (drawingCoin == true) {
        glPushMatrix();
        glTranslatef(2.25, -0.5, 0);
        glScalef(0.1, 0.1, 1);
        drawCoin();
        glPopMatrix();
    }
}

// mostra ponstuacao na tela
void Jogo::drawScore() {
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
    
    // Definir a cor e o tamanho do texto
    glColor3f(0, 0, 0); // Preto
    glRasterPos3f(0.1, 650, 1); // Posição do texto na tela
    glScalef(0.1f, 0.1f, 1.0f); // Escala do texto

    // Converter a pontuação para string
    std::string pontuacaoString = "Pontuacao: " + std::to_string(pontuacao);

    // Exibir a pontuação
    for (char c : pontuacaoString) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    
}