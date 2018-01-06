#pragma once

#include "iostream"
#include <SFML/Graphics.hpp>
#include "Block.h"

using namespace std;
using namespace sf;

class World
{
public:
	static const int w = 40;
	static const int h = 22;

	Block blocks[h][w];

	World();

	void generate();
};
