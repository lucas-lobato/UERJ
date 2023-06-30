#pragma once
#include "Primitivas.hpp"

class Cenario : public Primitivas
{
public:
	bool drawingCoin = true;
	bool coletou = false;
	float cloudMovement = 0;
	clock_t tempo = clock();

public:
	void drawGarden(void);
	void drawClouds(void);
	void drawCloud(void);
	void drawScene(void);
	void drawCoin(void);
	void drawCenario(void);
	void drawCaixa(void);
	void drawCaixas(void);
};

