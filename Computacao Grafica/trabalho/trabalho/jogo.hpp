#pragma once
#include <string>
#include "Personagem.hpp"
#include "Missil.hpp"

class Jogo: public Personagem, public Missil
{
public:
	int width = 1000;
	int height = 500;
	bool gameOver = false;
	int pontuacao = 0;

public:
	bool colisionBoxCheckD(void);
	bool colisionBoxCheckA(void);
	bool colisionBoxCheckW(void);
	bool colisionBoxCheckS(void);
	bool colisionMissileCheck(void);
	void drawGameOverScreen(void);
	void drawCoins(void);
	void colisionCoinCheck(void);
	void drawScore(void);
};

