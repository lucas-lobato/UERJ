#pragma once
#include "Cenario.hpp"

class Personagem: public Cenario
{
public:
	float characterPosX = 0, characterPosZ = 0;

	int contadorX = 0;
	int contadorZ = 0;
	float zRotation = 90;

	float angleLeftLeg = 0.0;
	float angleRightLeg = 0.0;
	float angleLeftArm = 0.0;
	float angleRightArm = 0.0;
	bool leftLegDescendo = false;
	bool rightLegDescendo = true;
	bool leftArmDescendo = false;
	bool rightArmDescendo = true;

public:
	void update();
	void characterMovementX(float);
	void characterMovementZ(float);
	void drawCharacter(void);
};

