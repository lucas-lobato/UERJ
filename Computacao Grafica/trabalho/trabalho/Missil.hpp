#pragma once
#include "Primitivas.hpp"

class Missil : public Primitivas
{
public:
	float missilMovement = 0;
	float missilLocation = 0;

public:
	void drawMissile(void);
};

