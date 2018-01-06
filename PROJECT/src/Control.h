#pragma once

#include "iostream"
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace std;
using namespace sf;

class Control
{
public:
	Player *player;

	Control();
	Control(Player &player);

	void controlPlayer(RenderWindow &window);
};

