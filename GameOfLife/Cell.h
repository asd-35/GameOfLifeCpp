#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;

class Cell //cell class
{
public:
	FloatRect getPosition();
	bool isAlive();
	Sprite getSprite();
	void update(Time elapsed);
	void spawn(int x, int y, bool isAlive);
private:
	bool cellStatus;
	Sprite cellSprite;
	Vector2f cellPos;
};



