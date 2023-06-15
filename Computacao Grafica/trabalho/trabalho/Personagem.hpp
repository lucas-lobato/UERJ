#pragma once
#include <GL/glut.h>
#include <math.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

class Personagem
{
public:
	float characterPosX = 0, characterPosY = 0;
	float cloudMove = 0;
	int rightArm = 0, leftArm = 0, leftLeg = 0, rightLeg = 0;
	int contador = 0;
public:
	void characterMovement(float);
	void drawCharacter(void);
	void jumping(void);
};

