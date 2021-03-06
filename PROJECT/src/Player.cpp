#include "Player.h"

Player::Player()
{
	this->x = 608;
	this->y = 560;
	this->r = 0;

	state = state::none;

	init();
	move();
}

void Player::move()
{
	if (this->state == state::none)
	{
		r = 0;
		d = 1;
		renderFront();
	}
	else if (this->state == state::left)
	{
		left();
	}
	else if (this->state == state::right)
	{
		right();
	}
	else if (this->state == state::down)
	{
		down();
	}
	else if (this->state == state::up)
	{
		up();
	}
	else if (this->state == state::jump)
	{
		jump();
	}
}

void Player::jump()
{
	renderFront();
	animateJump();
	y--;
}

void Player::left()
{
	renderLeft();
	animateLeft();
	x--;
}

void Player::right()
{
	renderRight();
	animateRight();
	x++;
}

void Player::down()
{
	renderFront();
	animateSit();
}

void Player::up()
{
	renderBack();
}

void Player::init()
{
	texture.loadFromFile("res/steve.png");
	head.setTexture(texture);

	body.setTexture(texture);
	arm1.setTexture(texture);
	arm2.setTexture(texture);
	leg1.setTexture(texture);
	leg2.setTexture(texture);
}

void Player::renderFront()
{
	default();

	head.setTextureRect(IntRect(32, 32, 32, 32));
	body.setTextureRect(IntRect(80, 80, 32, 48));
	arm1.setTextureRect(IntRect(176, 80, 16, 48));
	arm2.setTextureRect(IntRect(208, 80, 16, 48));
	leg1.setTextureRect(IntRect(16, 80, 16, 48));
	leg2.setTextureRect(IntRect(48, 80, 16, 48));

	head.setPosition(x, y);
	body.setPosition(x, y + 32);
	arm1.setPosition(x, y + 32);
	arm2.setPosition(x + 32, y + 32);
	leg1.setPosition(x + 16, y + 32 + 48);
	leg2.setPosition(x + 16, y + 32 + 48);
}

void Player::renderLeft()
{
	head.setTextureRect(IntRect(64, 32, 32, 32));
	body.setTextureRect(IntRect(112, 80, 16, 48));
	arm2.setTextureRect(IntRect(160, 80, 16, 48));
	arm1.setTextureRect(IntRect(192, 80, 16, 48));
	leg2.setTextureRect(IntRect(0, 80, 16, 48));
	leg1.setTextureRect(IntRect(32, 80, 16, 48));

	head.setPosition(x, y);
	body.setPosition(x + 8, y + 32);
	arm1.setPosition(x + 24, y + 32);
	arm2.setPosition(x + 8, y + 32);
	leg1.setPosition(x + 24, y + 32 + 48);
	leg2.setPosition(x + 8, y + 32 + 48);
}

void Player::renderRight()
{
	head.setTextureRect(IntRect(0, 32, 32, 32));
	body.setTextureRect(IntRect(64, 80, 16, 48));
	arm1.setTextureRect(IntRect(160, 80, 16, 48));
	arm2.setTextureRect(IntRect(192, 80, 16, 48));
	leg1.setTextureRect(IntRect(0, 80, 16, 48));
	leg2.setTextureRect(IntRect(32, 80, 16, 48));

	head.setPosition(x, y);
	body.setPosition(x + 8, y + 32);
	arm2.setPosition(x + 8, y + 32);
	arm1.setPosition(x + 24, y + 32);
	leg2.setPosition(x + 8, y + 32 + 48);
	leg1.setPosition(x + 24, y + 32 + 48);
}

void Player::renderBack()
{
	head.setTextureRect(IntRect(96, 32, 32, 32));
	body.setTextureRect(IntRect(128, 80, 32, 48));
	arm2.setTextureRect(IntRect(160, 80, 16, 48));
	arm1.setTextureRect(IntRect(192, 80, 16, 48));
	leg2.setTextureRect(IntRect(0, 80, 16, 48));
	leg1.setTextureRect(IntRect(32, 80, 16, 48));

	head.setPosition(x, y);
	body.setPosition(x, y + 32);
	arm1.setPosition(x, y + 32);
	arm2.setPosition(x + 32, y + 32);
	leg1.setPosition(x + 16, y + 32 + 48);
	leg2.setPosition(x + 16, y + 32 + 48);
}

void Player::animateJump()
{
	animate();
	arm1.setRotation(r);
	arm2.setRotation(-r);
	leg1.setRotation(r);
	leg2.setRotation(-r);
}

void Player::animateLeft()
{
	animate();
	arm1.setRotation(-r);
	arm2.setRotation(r);
	leg1.setRotation(r);
	leg2.setRotation(-r);
}

void Player::animateRight()
{
	animate();
	arm1.setRotation(-r);
	arm2.setRotation(r);
	leg1.setRotation(r);
	leg2.setRotation(-r);
}

void Player::animateSit()
{
	head.setTextureRect(IntRect(32, 0, 32, 32));
	
	head.setPosition(x, y + 2);
	body.setPosition(x, y + 34);

	r += 1;
	if (r > 10)
		r = 10;

	arm1.setRotation(r);
	arm2.setRotation(-r);
}

void Player::animate()
{
	r += d;
	if (r > 30 || r < 0)
		d = -d;
}

void Player::default()
{
	arm1.setOrigin(16, 0);
	arm2.setOrigin(0, 0);
	leg1.setOrigin(16, 0);
	leg2.setOrigin(0, 0);

	arm1.setRotation(0);
	arm2.setRotation(0);
	leg1.setRotation(0);
	leg2.setRotation(0);
}
