#include "Personagem.hpp"


// Atualiza a posição do personagem na cordenada X
void Personagem::characterMovementX(float movement) {
    characterPosX = characterPosX + movement;
    if (movement < 0) {
        contadorX = contadorX - 2;
    }
    if (characterPosX >= 4) {
        characterPosX = 0;
        drawingCoin = true;
        coletou = false;
    }
    if (characterPosX <= -0.1) {
        characterPosX = characterPosX - movement;
    }
    contadorX = contadorX + 1;
}

// Atualiza a posição do personagem na cordenada Z
void Personagem::characterMovementZ(float movement) {
    characterPosZ = characterPosZ + movement;
    if (movement < 0) {
        contadorZ = contadorZ - 2;
    }
    if (characterPosZ >= 0.2) {
        characterPosZ = characterPosZ - movement;
    }
    if (characterPosZ <= -0.2) {
        characterPosZ = characterPosZ - movement;
    }
    contadorZ = contadorZ + 1;
}

// Função de atualização do movimento
void Personagem::update() {
    // Verifica se os ângulos estão dentro do intervalo correto

    //Perna esquerda
    if (angleLeftLeg == 70.0f) {
        leftLegDescendo = true;
    }
    if (angleLeftLeg == - 70.0f) {
        leftLegDescendo = false;
    }
    if (leftLegDescendo == true) {
        angleLeftLeg -= 10.0f; //atualiza o angulo
    }
    if (leftLegDescendo == false) {
        angleLeftLeg += 10.0f; //atualiza o angulo
    }

    //Perna direita
    if (angleRightLeg == 70.0f) {
        rightLegDescendo = true;
    }
    if (angleRightLeg == -70.0f) {
        rightLegDescendo = false;
    }
    if (rightLegDescendo == true) {
        angleRightLeg -= 10.0f; //atualiza o angulo
    }
    if (rightLegDescendo == false) {
        angleRightLeg += 10.0f; //atualiza o angulo
    }

    //braço esquerdo
    if (angleLeftArm == 70.0f) {
        leftArmDescendo = true;
    }
    if (angleLeftArm == -70.0f) {
        leftArmDescendo = false;
    }
    if (leftArmDescendo == true) {
        angleLeftArm -= 10.0f; //atualiza o angulo
    }
    if (leftArmDescendo == false) {
        angleLeftArm += 10.0f; //atualiza o angulo
    }
    
    //braço direito
    if (angleRightArm == 70.0f) {
        rightArmDescendo = true;
    }
    if (angleRightArm == -70.0f) {
        rightArmDescendo = false;
    }
    if (rightArmDescendo == true) {
        angleRightArm -= 10.0f; //atualiza o angulo
    }
    if (rightArmDescendo == false) {
        angleRightArm += 10.0f; //atualiza o angulo
    }
}

// Desenha o personagem
void Personagem::drawCharacter()
{
    glColor3f(1.0, 0.0, 0.0);

    // Cabeça
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glutSolidSphere(0.5f, 20, 20);
    glPopMatrix();

    // Corpo
    glTranslatef(0.0f, -1.0f, 0.0f);
    glScalef(1.0f, 2.0f, 0.5f);
    glutSolidCube(1.0f);

    // Braços
    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-0.75f, 0.3f, 0.0f);
    glRotatef(angleLeftArm, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -0.5f, 0.0f);
    glScalef(0.5f, 1.0f, 0.5f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(0.75f, 0.3f, 0.0f);
    glRotatef(angleRightArm, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -0.5f, 0.0f);
    glScalef(0.5f, 1.0f, 0.5f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Pernas
    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-0.25f, -0.5f, 0.0f);
    glRotatef(angleLeftLeg, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -0.5f, 0.0f);
    glScalef(0.5f, 1.5f, 0.5f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(0.25f, -0.5f, 0.0f);
    glRotatef(angleRightLeg, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -0.5f, 0.0f);
    glScalef(0.5f, 1.5f, 0.5f);
    glutSolidCube(1.0f);
    glPopMatrix();
}
