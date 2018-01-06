#include "Control.h"

Control::Control()
{
}

Control::Control(Player & player)
{
	this->player = &player;
}

void Control::controlPlayer(RenderWindow &window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
		if (event.type == Event::KeyReleased)
			player->state = state::none;
	}

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player->state = state::up;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player->state = state::down;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player->state = state::right;
	} 
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player->state = state::left;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		player->state = state::jump;
	}
}
