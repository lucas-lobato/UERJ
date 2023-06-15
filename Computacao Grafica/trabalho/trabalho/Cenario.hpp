#pragma once
#include <GL/glut.h>
#include <math.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

class Cenario
{
public:
	float cloudMove = 0;
	bool drawingCoin = 0;
	float scene1Replay = 0, scene2Replay= 0, displayMovement = 0;
public:
	void drawSun(void);
	void drawGarden(void);
	void drawMontain(void);
	void drawWindTurbine(void);
	void drawPropellers(void);
	void drawTurbinesPropellers(void);
	void drawbackground(void);
	void drawHouse(void);
	void drawTelhadoCasa(void);
	void drawTelhadoGaragem(void);
	void drawHills(void);
	void drawTrees(void);
	void drawRoundTree(void);
	void drawRoundTrees(void);
	void drawTriangleTree(void);
	void drawTriangleTrees(void);
	void drawCircleTree(void);
	void drawCircleTrees(void);
	void drawTurbines(void);
	void drawClouds(void);
	void drawCloud(void);
	void drawScene(void);
	void drawCoin(void);
	void drawCoins(void);
};

