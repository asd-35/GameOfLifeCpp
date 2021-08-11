#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;

class Cell //cell class
{
public:
	
	Cell(float x, float y, bool stat, Texture* text);
	
	FloatRect getPosition();
	Sprite getSprite();

	bool isAlive();
	void update(float x, float y, Texture* text);
	
private:
	bool cellStatus;
	Sprite cellSprite;
	Vector2f cellPos;
};



