#include "World.h"

World::World()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			blocks[i][j] = Block(0);
		}
	}

	generate();
}

void World::generate()
{
	for (int i = 0; i < w; i++)
	{
		Block block(4);
		blocks[h - 1][i] = block;
	}
}
