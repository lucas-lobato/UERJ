#pragma once
#include <GL/glut.h>
#include "texturas/stb_image.h"
#include <iostream>


class SkyBox
{
public:
	GLuint textureIDs[6];
public:
	void loadSkyboxTextures();
	void drawSkybox();
};

