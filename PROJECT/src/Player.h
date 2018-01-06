#pragma once

#include "iostream"
#include <SFML/Graphics.hpp>
#include "Object.h"

using namespace std;
using namespace sf;

enum state
{
	jump,
	none,
	left,
	right,
	down,
	up
};

class Player
{
public:
	int x;
	int y;
	int r;
	int d;
	//rect 128 / 64
	bool inSpace;
	state state;

	Texture texture;

	Sprite head;
	Sprite body;
	Sprite arm1;
	Sprite arm2;
	Sprite leg1;
	Sprite leg2;

	Player();

	void jump();
	void move();
	void left();
	void right();
	void down();
	void up();
	void init();

	void renderFront();
	void renderLeft();
	void renderRight();
	void renderBack();

	void animateJump();
	void animateLeft();
	void animateRight();
	void animateSit();

	void animate();
	void default();
};
