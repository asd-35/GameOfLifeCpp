#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;

class Cell
{
public:
	
	
	FloatRect getPosition();
	bool isAlive();
	Sprite getSprite();
	void update(Time elapsed);
private:
	bool isAlive;
	Sprite cellSprite;
	Vector2f cellPos;
	
};



