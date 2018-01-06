#include "Graphic.h"

Graphic::Graphic(World &world, Player &player, int w, int h)
{
	this->world = &world;
	this->player = &player;

	this->w = w;
	this->h = h;

	load();
}

void Graphic::draw(RenderWindow &window)
{
	window.draw(back);
	window.draw(logo.sprite);

	for (int i = 0; i < world->h; i++)
	{
		for (int j = 0; j < world->w; j++)
		{
			int index = world->blocks[i][j].index;
			if (index != 0)
			{
				textures.sprite.setTextureRect(IntRect(Block::size * (index - 1), 0, Block::size, Block::size));
				textures.sprite.setPosition(j * Block::size, i * Block::size + magic);
				window.draw(textures.sprite);
			}
		}
	}
	
	window.draw(player->head);
	window.draw(player->body);
	window.draw(player->arm1);
	window.draw(player->arm2);
	window.draw(player->leg1);
	window.draw(player->leg2);
}

void Graphic::load()
{	
	back.setSize(Vector2f(w, h));
	back.setFillColor(Color(100, 215, 250));

	logo.init("res/logo.png", 845, 200);
	logo.sprite.setPosition(w / 2 - logo.w / 2, 0);

	textures.init("res/textures.png", 512, 512);
}

