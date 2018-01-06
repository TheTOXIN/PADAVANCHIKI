#include "iostream"
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Block.h"
#include "Item.h"
#include "Player.h"
#include "World.h"
#include "Graphic.h"
#include "Audio.h"
#include "Control.h"

using namespace std;
using namespace sf;

int h = 720;
int w = 1280;

float temp = 5000;
float tick = 0;

int main()
{
	Image icon;
	icon.loadFromFile("res/icon.png");

	RenderWindow window(VideoMode(w, h), "CCraft");
	//window.setFramerateLimit(60);
	window.setIcon(32, 32, icon.getPixelsPtr());

	World world;
	Player player;
	Control control(player);
	Graphic graphic(world, player, w, h);
	Clock clock;

	while (window.isOpen())
	{
		tick += clock.getElapsedTime().asMicroseconds();
		clock.restart();

		if (tick > temp)
		{
			control.controlPlayer(window);
			player.move();
			tick = 0;
		}

		window.clear();
		graphic.draw(window);
		window.display();
	}

	return 1;
}