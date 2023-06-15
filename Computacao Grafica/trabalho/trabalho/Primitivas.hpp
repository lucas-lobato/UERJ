#pragma once
#include <GL/glut.h>
#include <math.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#define PI 3.14159265

class Primitivas
{
public:
	void drawTriangle();
	void drawPolygon();
	void drawSquare();
	void drawDisk(double radius);
};

