#pragma once
enum class eDir { STOP = 0, LEFT, RIGHT, UP, DOWN };
class Snake {
public:
	Snake();
	Snake(bool gameOver_, int x_,int y_, int fruitX_, int fruitY_, int tailX_[100], int tailY_[100], int nTail_, int width_, int height_, int score_, eDir dir_);
	Snake(const Snake& c);

	~Snake();

	void draw();
	void input();
	void logic();

	void PLAY();										// START GAME!!!
	void Restart();										// Inicialization poly class posle ~ clasa
	void Rules();										// PRAVILA IGRY!!!

private:
	bool gameOver;										// WIN / TO LOSE
	int x, y;											// Koordinati snake
	int fruitX, fruitY;									// Koordinati frukt
	int tailX[100], tailY[100];							// Koordinati XBOST
	int nTail;											// count XBost
	int width;											// Shirina
	int height;											// Bisota	
	int score;											// Schet
	eDir dir;
};
